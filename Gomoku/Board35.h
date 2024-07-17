#ifndef BOARD35_H
#define BOARD35_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QVector>
#include <QDebug>
#include <vector>
#include <iostream>
#include "chessitem.h"
#include "Node.h"
#include <QMessageBox>
#include <QPixmap>
#include <QPalette>

#define ChessR 12
#define ChessC 12
#define MaxX 35
#define MaxY 35

QT_BEGIN_NAMESPACE
namespace Ui {
class Board35;
}
QT_END_NAMESPACE

class Board35 : public QWidget
{
    Q_OBJECT

public:
    Board35(QWidget *parent = nullptr);
    ~Board35();

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event); //鼠标变形

    int CountNearItem(ChessItem item , QPoint pt); //判断棋子连接

private:
    Ui::Board35 *ui;
    void InitUI();
    void DrawChessBoard();//画棋盘
    void DrawChessItem();//绘制棋盘上的棋子
    void DrawChessAtPoint(QPainter &painter , QPoint &point); //画棋子的样式和位置
    bool is_valid_move(int row, int col);//ai部分判断落子合法性
    void clear_board();//清空数据
    void ai_move();//ai落子
    bool b_black; //定义棋子的颜色

    QVector<ChessItem> p_ChessItem;//存储棋子

};
#endif // BOARD35_H
