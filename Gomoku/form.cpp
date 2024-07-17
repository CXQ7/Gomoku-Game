#include "form.h"
#include "Board35.h"
#include "Board4o.h"
#include "form.h"
#include "ui_form.h"

const int BOARD_SIZE = 12;
std::vector<std::vector<char>> board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, ' '));

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_gomoku_gpt35_btn_clicked()
{
    Board35 *board35 = new Board35;
    board35->show();
    this->hide();
}

void Form::on_gomoku_gpt4o_btn_clicked()
{
    Board4o *board4o = new Board4o;
    board4o->show();
    this->hide();
}