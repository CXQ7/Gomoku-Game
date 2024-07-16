#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QVector>
#include <QDebug>
#include "chessitem.h"
#include <QMessageBox>

#define ChessR 12
#define ChessC 12
#define MaxX 35
#define MaxY 35

QT_BEGIN_NAMESPACE
namespace Ui {
class Board;
}
QT_END_NAMESPACE

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget *parent = nullptr);
    ~Board();

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event); //鼠标变形

    int CountNearItem(ChessItem item , QPoint pt); //判断棋子连接

private:
    Ui::Board *ui;
    void InitUI();
    void DrawChessBoard();//画棋盘
    void DrawChessItem();//绘制棋盘上的棋子
    void DrawChessAtPoint(QPainter &painter , QPoint &point); //画棋子的样式和位置

    bool b_black; //定义棋子的颜色

    QVector<ChessItem> p_ChessItem;//存储棋子

};
#endif // BOARD_H
