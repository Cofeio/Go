
#ifndef GO_BOARD_H
#define GO_BOARD_H

using namespace std;
#include <string>
#include <iostream>
#include <cmath>



class Board {
private:
    string position;
    string board[19][19];
    bool whiteTaken[19][19] = {false};
    bool blackTaken[19][19] = {false};
    int bScore = 0;
    int wScore = 0;
public:
    void startGame(){
        for(int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                board[i][j] = ". ";
            }

        }
        board[3][3] = "* ";
        board[9][3] = "* ";
        board[15][3] = "* ";
        board[3][15] = "* ";
        board[3][9] = "* ";
        board[9][9] = "* ";
        board[9][15] = "* ";
        board[15][9] = "* ";
        board[15][15] = "* ";
    }
    void showPosition(int x, int y){
        cout << board[x][y];
    }
    void showBoard(){
        for (int i = 0; i < 19; i++) {
            cout << endl;
            for (int j = 0; j < 19; j++) {
                showPosition(i, j);
            }
        }
    }
    bool placeBlack(int x, int y){
        y -= 18;
        if(!whiteTaken[abs(y)+1][x-1] and !blackTaken[abs(y)+1][x-1]){
            board[abs(y)+1][x-1] = "# ";
            blackTaken[abs(y)+1][x-1] = true;
            cout << endl << endl<< endl<< endl<< endl<< endl;
            showBoard();
            return true;
        } else {
            cout << "Space occupied";
            return false;
        }
        
    }
    bool placeWhite(int x, int y){
        y -= 18;
        if(!whiteTaken[abs(y)+1][x-1] and !blackTaken[abs(y)+1][x-1]){
            board[abs(y)+1][x-1] = "0 ";
            whiteTaken[abs(y)+1][x-1] = true;
            cout << endl << endl<< endl<< endl<< endl<< endl;
            showBoard();
            return true;
        } else {
            cout << "Space occupied";
            return false;
        }
    }
    void revert(int x, int y){
        y-=18;
        if(blackTaken[abs(y)+1][x-1]){
            wScore += 1;
            board[abs(y)+1][x-1] = ". ";
        }
        else if(whiteTaken[abs(y)+1][x-1]){
            bScore += 1;
            board[abs(y)+1][x-1] = ". ";
        }
        else {
            cout << "Not valid space";
        }
    }
    void getScore(){
        cout << "Black has " << bScore << " Points" << endl;
        cout << "White has " << wScore << " Points" << endl;

    }
};




#endif //GO_BOARD_H
