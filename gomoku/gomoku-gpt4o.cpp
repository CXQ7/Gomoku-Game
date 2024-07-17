#include <iostream>
#include <vector>
#include "openai.hpp"  
#include "nlohmann/json.hpp"
using json = nlohmann::json;

const int BOARD_SIZE = 15;
std::vector<std::vector<char>> board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, ' '));

struct Node{
    int x;int y;
};

void print_board() {
    std::cout << "  ";
    for (int i = 0; i < BOARD_SIZE; ++i)
        std::cout << i << ' ';
    std::cout << "\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        std::cout << i << ' ';
        for (int j = 0; j < BOARD_SIZE; ++j)
            std::cout << board[i][j] << ' ';
        std::cout << "\n";
    }
}

bool is_valid_move(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

bool check_win(int row, int col, char player) {
    int count = 0;

    // 列
    for (int c = std::max(0, col - 4); c <= std::min(BOARD_SIZE - 1, col + 4); ++c) {
        if (board[row][c] == player) {
            count++;
            if (count >= 5) return true;
        } else {
            count = 0;
        }
    }

    // 行
    count = 0;
    for (int r = std::max(0, row - 4); r <= std::min(BOARD_SIZE - 1, row + 4); ++r) {
        if (board[r][col] == player) {
            count++;
            if (count >= 5) return true;
        } else {
            count = 0;
        }
    }

    // 对角线（从左上到右下）
    count = 0;
    for (int d = -4; d <= 4; ++d) {
        int r = row + d, c = col + d;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
            if (board[r][c] == player) {
                count++;
                if (count >= 5) return true;
            } else {
                count = 0;
            }
        }
    }

    // 对角线（从右上到左下）
    count = 0;
    for (int d = -4; d <= 4; ++d) {
        int r = row - d, c = col + d;
        if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
            if (board[r][c] == player) {
                count++;
                if (count >= 5) return true;
            } else {
                count = 0;
            }
        }
    }

    return false;
}

void make_move(int row, int col, char player) {
    board[row][col] = player;
}//玩家落子

Node get_ai_move() {
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
    
    // std::cout<<"black: "<<s1<<std::endl;
    // std::cout<<"white: "<<s2<<std::endl;
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
     make_move(row, col, 'O');
     Node q;
     q.x=row;q.y=col;
     return q;
}//AI落子


int main() {

    int row, col;
    char player = 'X';
    Node p;

    print_board();

    while (true) {
        std::cout << "Player " << player << ", enter your move (row column): ";
        std::cin >> row >> col;

        if (is_valid_move(row, col)) {
            make_move(row, col, player);
            print_board();

            if (check_win(row, col, player)) {
                std::cout << "Player " << player << " wins!\n";
                break;
            }

            // 执棋手交换
            player = (player == 'X') ? 'O' : 'X';

            // AI执棋
            p=get_ai_move();
            print_board();
            row=p.x;col=p.y;

            if (check_win(row, col, player)) {
                std::cout << "Player " << player << " wins!\n";
                break;
            }

            // 执棋手交换
            player = (player == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move. Try again.\n";//判断重复落子
        }
    }

    return 0;
}
