#include "mainwindow.h"
#include "Board.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_game_start_button_clicked()
{
    Board *board = new Board;
    board->show();
    this->hide();
}
