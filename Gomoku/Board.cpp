#include "Board.h"
#include "mainwindow.h"
#include "./ui_Board.h"

Board::Board(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Board)
{
    ui->setupUi(this);
    InitUI();
}

Board::~Board()
{
    delete ui;
}

void Board::InitUI()
{
    //定义棋盘的大小
    this->resize((ChessC + 1) * MaxX, (ChessR + 1) * MaxX);
    DrawChessBoard();
    b_black = false;
}

void Board::DrawChessBoard()
{
    QPainter painter(this);
    painter.setPen(QPen(QColor(Qt::black),2));
    painter.setBrush(Qt::white);
    //棋盘格子
    for(int i=0; i <ChessC; i++){
        for(int j =0; j<ChessR;j++){
            painter.drawRect((i+0.5)*MaxX,(j+0.5)*MaxY,MaxX,MaxY);
        }
    }
}



//绘制棋盘上的所有棋子
void Board::DrawChessItem()
{
    QPainter painter(this);
    painter.setPen(QPen(QColor(Qt::black),1));
    //遍历棋子，有就绘制，没有就不绘制
    for(int i = 0; i < p_ChessItem.size() ; i++){
        ChessItem item = p_ChessItem[i]; //当前棋子的样式和位置复制给棋子这个类
        if(item._black){
            painter.setBrush(Qt::black);
        }else {
            painter.setBrush(Qt::white);
        }
        DrawChessAtPoint(painter,item._pt);
    }
}

void Board::DrawChessAtPoint(QPainter &painter , QPoint &point)
{
    //获取棋子的摆放位置
    QPoint ptCenter((point.x() + 0.5) * MaxX , (point.y() + 0.5) * MaxY);
    painter.drawEllipse(ptCenter,MaxX/3,MaxY/3);
}


void Board::mousePressEvent(QMouseEvent *event)
{

    QPoint pt;  //定义点位
    pt.setX((event->pos().x())/MaxX);
    pt.setY((event->pos().y())/MaxY);

    //判断棋子是否存在
    for(int i = 0 ; i<p_ChessItem.size(); i++){
        ChessItem item = p_ChessItem[i];
        if(item._pt == pt){
            return ;
        }
    }

    //如果不存在，进行绘制和判断五子链接
    ChessItem item(pt,b_black);
    p_ChessItem.append(item);

    //统计四个点位是否连接
    int nLeft       = CountNearItem(item,QPoint(-1,0));
    int nLeftUp     = CountNearItem(item,QPoint(-1,-1));;
    int nUp         = CountNearItem(item,QPoint(0,-1));;
    int nRight      = CountNearItem(item,QPoint(1,0));;
    int nRightUp    = CountNearItem(item,QPoint(1,-1));;
    int nRightDown = CountNearItem(item,QPoint(1,1));;
    int nDown       = CountNearItem(item,QPoint(0,1));;
    int nLeftDown   = CountNearItem(item,QPoint(-1,1));;

    if( (nLeft + nRight) >= 4 || (nLeftUp + nRightDown) >=4
        || (nUp + nDown) >=4 || (nRightUp + nLeftDown) >= 4)
    {
        QString str = b_black ? "black win" : "white win";
        QMessageBox:: StandardButton result = QMessageBox::information(NULL,"GAME OVER",str + "!\ncontinue?",QMessageBox::Yes|QMessageBox::No);
        this->hide();
        MainWindow* menu = new MainWindow;
        switch (result)
        {
            case QMessageBox::Yes:
                menu->show();
                break;
            default:
                break;
        }
        return;
    }

    //换人下棋
    b_black = !b_black;
}

int Board::CountNearItem(ChessItem item, QPoint pt)
{
    int nCount = 0;

    item._pt += pt;
    while (p_ChessItem.contains(item)) {
        nCount++;
        item._pt += pt;
    }

    return nCount;
}


void Board::paintEvent(QPaintEvent *event)
{
    DrawChessBoard();
    DrawChessItem();
    update();
}


