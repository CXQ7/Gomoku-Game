#include "mainwindow.h"
#include "form.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QPixmap pixmap(":/menu/img/menu_background.jpg");
    QPalette palette1;
    palette1.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette1);
    /*QPixmap pixmap=QPixmap(":/menu/img/menu_background.jpg").scaled(this->size());
    QPalette palette;
    //设置主窗口背景图片
    palette.setBrush(QPalette::Window,QBrush(pixmap));*/
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
 
    QPixmap pixmap(":/menu/img/menu_background.jpg");
    painter.drawPixmap(this->rect(),pixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_game_start_button_clicked()
{
    Form *form = new Form;
    form->show();
    this->hide();
}
