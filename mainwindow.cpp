#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <textanalyzerwindow.h>
#include <stats.h>
#include <advancedstats.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tabs, &QTabWidget::tabCloseRequested, this, &MainWindow::closeTab);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_nfButton_clicked()
{
    QTextEdit *edit = new QTextEdit;
    int index = ui -> tabs -> addTab(edit, "unnamed");
    ui -> tabs -> setCurrentIndex(index);
    edit -> setFocus();
    filePaths.append("");
}


void MainWindow::on_oButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)" );
    if  (path.isEmpty()) return;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Opening file failed.");
        return;
    }
    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    QTextEdit *edit = new QTextEdit;
    edit->setPlainText(content);

    QFileInfo info(path);
    int index = ui->tabs->addTab(edit, info.fileName());
    ui->tabs->setCurrentIndex(index);

    filePaths.append(path);
}

QTextEdit* MainWindow::CurrEditor()
{
    int idx = ui -> tabs -> currentIndex();
    if (idx == -1) return nullptr;
    return qobject_cast<QTextEdit*>(ui -> tabs -> widget(idx));
}

void MainWindow::on_sButton_clicked()
{
    int idx = ui -> tabs -> currentIndex();
    if (idx == -1) return;

    QString path = filePaths.value(idx);
    if (path.isEmpty()) {
        on_saButton_clicked();
        return;
    }
    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << CurrEditor() -> toPlainText();
        file.close();
    }
}


void MainWindow::on_saButton_clicked()
{
    int idx = ui -> tabs -> currentIndex();
    if (idx == -1) return;

    QString path = QFileDialog::getSaveFileName(this, "Save File As", "", "Text Files (*.txt)");
    if (path.isEmpty()) return;

    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << CurrEditor() -> toPlainText();
        file.close();

        filePaths[idx] = path;
        QFileInfo info(path);
        ui -> tabs -> setTabText(idx, info.fileName());
    }
}


void MainWindow::closeTab(int idx)
{
    QWidget *w = ui->tabs->widget(idx);
    ui -> tabs -> removeTab(idx);
    delete w;
    filePaths.removeAt(idx);
}


void MainWindow::on_analyzeButton_clicked()
{
    QTextEdit *edit = CurrEditor();
    if (!edit) return; // jesli nie ma tabow wyjdz

    TextAnalyzerWindow dialog(this);
    if (dialog.exec() != QDialog::Accepted)
        return;

    QString ret;
    if (dialog.isAdvancedSelected()) {
        advancedstats a;
        a.analyze(edit -> toPlainText());
        ret = a.raport();
    } else {
        stats s;
        s.analyze(edit -> toPlainText());
        ret = s.raport();
    }
    QMessageBox::information(this, "Statystyki", ret);
}

