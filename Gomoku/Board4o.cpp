#include "Board4o.h"
#include "mainwindow.h"
#include "./ui_Board4o.h"
#include "form.h"
#include "openai.hpp"  
#include "nlohmann/json.hpp"
using json = nlohmann::json;

const int BOARD_SIZE = 12;
extern std::vector<std::vector<char>> board;

Board4o::Board4o(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Board4o)
{
    ui->setupUi(this);
    InitUI();
}

Board4o::~Board4o()
{
    delete ui;
}

void Board4o::InitUI()
{
    //定义棋盘的大小
    this->resize((ChessC + 1) * MaxX, (ChessR + 1) * MaxX);
    DrawChessBoard();
    b_black = true;
}

void Board4o::DrawChessBoard()
{
    /*QPixmap pixmap("img/menu_background.jpg");
    QPalette palette1;
    palette1.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette1);
    this->setAutoFillBackground(true);*/
    ui->setupUi(this);
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
void Board4o::DrawChessItem()
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

void Board4o::DrawChessAtPoint(QPainter &painter , QPoint &point)
{
    //获取棋子的摆放位置
    QPoint ptCenter((point.x() + 0.5) * MaxX , (point.y() + 0.5) * MaxY);
    painter.drawEllipse(ptCenter,MaxX/3,MaxY/3);
}


void Board4o::mousePressEvent(QMouseEvent *event)
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

    board[pt.x()][pt.y()] = 'X';
    std::cout<<pt.x()<<' '<<pt.y()<<std::endl;

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
        clear_board();
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
    b_black = !b_black;
    ai_move();
}

bool Board4o::is_valid_move(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

void Board4o::clear_board() {
    for(int i=0;i<BOARD_SIZE;i++)
        for(int j=0;j<BOARD_SIZE;j++)
            board[i][j] = ' ';
}

void Board4o::ai_move() {
    int row,col,i,p;
    openai::start("sk-0DITh75zrxk-8tM6mhckTA","",true,"https://agino.me/");
    
    std::string s1="",s2="";

    for(int i=0;i<BOARD_SIZE;i++)
        for(int j=0;j<BOARD_SIZE;j++)
            if(board[i][j]=='X'){
                s1+='(';s1+=std::to_string(i);s1+=',';s1+=std::to_string(j);s1+=')';
            }
            else if(board[i][j]=='O'){
                s2+='(';s2+=std::to_string(i);s2+=',';s2+=std::to_string(j);s2+=')';
            }//记录目前棋盘上黑子与白子的坐标
    
    std::cout<<"black: "<<s1<<std::endl;
    std::cout<<"white: "<<s2<<std::endl;
    do{
        json board_state= {
            {"model","gpt-4o"},
            {
                "messages",{
                    {
                        {"role","user"},
                        {"content","Let us play Gomoku. The goal of the game is to get five in a row (horizontally, vertically, or diagonally) on a 15x15 board. You cannot occupy existed. The coordinates of multiple Gomoku black spots are "+s1+"and the coordinates of multiple Gomoku white spots are "+s2+". For each coordinate, the first number represents the row and the second represents the column. Please try your best to prevent your enemy from winning by blocking the most possible way of having 5 black on the same row, column or diagonal. Only tell me the coordinate of the white you move without telling me why. "}
                    }
                }
            }
        };//调用AI
        
        auto completion = openai::chat().create(board_state);

        //std::string c=board_state["messages"][0]["content"].get<std::string>();
        // std::cout<<c<<std::endl;
        std::string s=completion["choices"][0]["message"]["content"].get<std::string>();
        std::cout<<s<<std::endl;
        
        row = 0;col = 0;

        for(i=0;i<int(s.size());i++)
            if(s[i]>='0' && s[i]<='9'){
                row*=10;row+=s[i]-'0';
            }
            else if(s[i-1]>='0' && s[i-1]<='9') break;
        i++; p=i;
        bool flag=0;
        for(i=p;i<int(s.size());i++)
            if(s[i]>='0' && s[i]<='9'){
                col*=10;col+=s[i]-'0';flag=1;
            }
            else if(flag) break;
    }while(!is_valid_move(row,col));
    
    //将AI的回答中的坐标提取出来
    board[row][col] = 'O';

    QPoint pt;  //定义点位
    
    pt.setX(row);
    pt.setY(col);
    std::cout<<pt.x()<<' '<<pt.y()<<std::endl;

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
        clear_board();
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
    b_black = !b_black;
}//AI落子



int Board4o::CountNearItem(ChessItem item, QPoint pt)
{
    int nCount = 0;

    item._pt += pt;
    while (p_ChessItem.contains(item)) {
        nCount++;
        item._pt += pt;
    }

    return nCount;
}


void Board4o::paintEvent(QPaintEvent *event)
{
    DrawChessBoard();
    DrawChessItem();
    update();
}


