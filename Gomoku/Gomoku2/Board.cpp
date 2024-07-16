#include "Board.h"
#include "ui_Board.h"

Board::Board(QMainWindow *parent)
    : QMainWindow(parent)
    , ui(new Ui::Board)
{
    ui->setupUi(this);
}

Board::~Board()
{
    delete ui;
}
