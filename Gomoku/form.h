#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_gomoku_gpt35_btn_clicked();
    void on_gomoku_gpt4o_btn_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
