#include <iostream>
#include "Board.h"

using namespace std;


enum Positions {Empty, black, white, star};

int main() {
    bool game = true;
    Board board;
    board.startGame();
    board.showBoard();
    while(game == true){
        int x;
        int y;
        bool can;
        int play;
        cout << endl;
        board.getScore();
        cout << endl << endl;
        cout << "\n1. BlackMove\n";
        cout << "2. WhiteMove\n";
        cout << "3. Remove Stone\n";
        cout << "4. End Game\n";
        cout << "What do you wish to do? : ";
        cin >> play;
        


        switch(play){
            case 1:
                do{
                    cout << "\nBlack X: ";
                    cin >> x;
                    cout << "Black Y: ";
                    cin >> y;
                    can = board.placeBlack(x,y);
                }while(!can);
                break;
            case 2:
                do{
                    
                    cout << "\nWhite X: ";
                    cin >> x;
                    cout << "White Y: ";
                    cin >> y;
                    can = board.placeWhite(x,y);
                }while(!can); 
                break;
            case 3:
                cout << "What space?";
                cout << "\nX: ";
                cin >> x;
                cout << "Y: ";
                cin >> y;
                board.revert(x,y);
                board.showBoard();
                break;
            case 4:
                game = false;
                break;
            default:
                cout << "Sorry I missed that";
        }
    }
}





