#include "textanalyzerwindow.h"
#include "ui_textanalyzerwindow.h"

TextAnalyzerWindow::TextAnalyzerWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TextAnalyzerWindow)
{
    ui->setupUi(this);
    connect(ui -> okButton, &QPushButton::clicked, this, &QDialog::accept);
}

TextAnalyzerWindow::~TextAnalyzerWindow()
{
    delete ui;
}

bool TextAnalyzerWindow::isAdvancedSelected() const
{
    return ui -> radioAdvanced -> isChecked();
}

