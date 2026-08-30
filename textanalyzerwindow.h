#ifndef TEXTANALYZERWINDOW_H
#define TEXTANALYZERWINDOW_H

#include <QDialog>

namespace Ui {
class TextAnalyzerWindow;
}

class TextAnalyzerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TextAnalyzerWindow(QWidget *parent = nullptr);
    ~TextAnalyzerWindow();
    bool isAdvancedSelected() const;

private:
    Ui::TextAnalyzerWindow *ui;
};

#endif // TEXTANALYZERWINDOW_H
