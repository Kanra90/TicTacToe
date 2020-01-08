using namespace std;
#include <iostream>
#include "board.h"

char board::printBoard(){
    for ( int i=0; i<3; i++){
        for ( int j=0; j<3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
char board::checkWin(){
    //check horizontal rows
    for(int i=0,j=0;i<3;i++){
        if(board[i][j]==board[i][j+1] && board[i][j+1]==board[i][j+2]){
            return board[i][j];
        }
    }
    //check vertical rows
    for(int i=0,j=0;j<3;j++){
        if(board[i][j]==board[i+1][j] && board[i+1][j]==board[i+2][j]){
            return board[i][j];
        }
    }
    //check diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        //found Winner, return victor
        return board[0][0];
    }else if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        return board[2][0];
    }else{
        return 'f';
    }
}
void board::input(){
    printBoard();
    int a;
    cout << "Enter the number of the field you wish to make a move:";
    cin >> a;
    turnClock++;

    switch(a){
        case 1:
            board[0][0] = player;
            break;
        case 2:
            board[0][1] = player;
            break;
        case 3:
            board[0][2] = player;
            break;
        case 4:
            board[1][0] = player;
            break;
        case 5:
            board[1][1] = player;
            break;
        case 6:
            board[1][2] = player;
            break;
        case 7:
            board[2][0] = player;
            break;
        case 8:
            board[2][1] = player;
            break;
        case 9:
            board[2][2] = player;
            break;
    }

}

void board::move_AI(char a){
    turnClock++;
    switch(a){
        case '1':
            board[0][0] = ai;
            break;
        case '2':
            board[0][1] = ai;
            break;
        case '3':
            board[0][2] = ai;
            break;
        case '4':
            board[1][0] = ai;
            break;
        case '5':
            board[1][1] = ai;
            break;
        case '6':
            board[1][2] = ai;
            break;
        case '7':
            board[2][0] = ai;
            break;
        case '8':
            board[2][1] = ai;
            break;
        case '9':
            board[2][2] = ai;
            break;
    }
}
bool board::movesLeft(){
    bool moves = false;
    //look for an empty spot
    for ( int i=0; i<3; i++){
        for ( int j=0; j<3; j++){
            if(board[i][j]!='X' && board[i][j]!='O'){
                //empty spot found, are moves left
                return true;
            }
        }
        //no moves, full board
        return false;
    }
}