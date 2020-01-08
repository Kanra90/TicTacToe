using namespace std;
#include <iostream>
#include "board.h"
#include "game_AI.h"

int main(){
    board b;
    game_AI ai;
    int turnClock = 0;
    cout << "Welcome to TicTacToe!" << endl;
    cout << "In this game, you will always go first as Player X!" << endl;
    do{
        //get input from user
        b.input();
        //check if player has won
        if(b.checkWin()=='X'){
            cout << "You have won!" << endl;
            b.printBoard();
            return 0;
        }
        turnClock++;

        //get best ai move on board given
        char best = ai.bestMove(b.board);
        //make move
        b.move_AI(best);
        //check if computer has won        
        if(b.checkWin()=='O'){
            cout << "Computer has won!" << endl;
            b.printBoard();
            return 0;
        }
        turnClock++;
    }while(turnClock<=9 && (b.checkWin()=='f'));

    //if 9 turns has passed w/ no winner, declare tie
    if(turnClock>=9){
        cout << "The Game is a Tie!" << endl;
        return 0;
    }

    return 0;
}