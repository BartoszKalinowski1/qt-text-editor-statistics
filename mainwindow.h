#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_nfButton_clicked();

    void on_oButton_clicked();

    void on_sButton_clicked();

    void on_saButton_clicked();

    void closeTab(int idx);

    void on_analyzeButton_clicked();

private:
    Ui::MainWindow *ui;
    QStringList filePaths;
    QTextEdit* CurrEditor();
};
#endif // MAINWINDOW_H
