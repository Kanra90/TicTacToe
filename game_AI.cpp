using namespace std;
#include <iostream>
#include "game_AI.h"

/**
 * Evaluate function will take in a board and evaluate the score of that board based on if we can win,
 * if an opponent can win, or if no win or loss could be found. 
 * 
 * **/
int game_AI::evaluate(char board[3][3]){
    //check horizontal rows
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            //found a win
            if(board[i][0]=='O'){
                return +10;
            }else if(board[i][0]=='X'){
                return -10;
            }
        }
    }
    //check vertical rows
    for(int j=0;j<3; j++){
        if(board[0][j]==board[1][j] && board[1][j]==board[2][j]){
            //found a win
            if(board[0][j]=='O'){
                return +10;
            }else if(board[0][j]=='X'){
                return -10;
            }
        }
    }
    //check diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        //found a win
        if(board[0][0]=='O'){
            return +10;
        }else if(board[0][0]=='X'){
            return -10;
        }
    }else if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        //found a win
        if(board[0][2]=='O'){
            return +10;
        }else if(board[0][2]=='X'){
            return -10;
        }
    }
    //no win or loss
    return 0;
}

bool game_AI::movesLeft(char board[3][3]){
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
/**
 * Minimax recursive function is a depth first search to find the resulting score of the board 
 * given based on 'simulated' best and worst moves
 * **/
int game_AI::minimax(int depth, char board[3][3],bool maximize){
    //evaluate score of board given
    int value = evaluate(board);
    //check score, if we found a resulting score, return value
    if(value==10 || value==-10){
        return value;
    //no moves left
    }else if(movesLeft(board)==false){
        return 0;
    }
    //max
    if(maximize){
        //arbitrary set max to 'beat'
        int current_Best = -10000;
        //traverse board, look for available moves
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                //check if empty, available move
                if(board[i][j] != 'X' && board[i][j] != 'O'){
                    char tempValue = board[i][j];
                    board[i][j]='O';
                    //call recursively to choose best, negate max each time for each 'turn'
                    current_Best = (max( current_Best, minimax(depth+1, board, !maximize) ))-depth;
                    //reverse move to prev char
                    board[i][j] = tempValue;
                }
            }
        }
        return current_Best;
    //min
    }else{
        int current_Best = 10000;
        //traverse board, look for available moves
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                //check if empty, available move
                if(board[i][j] != 'X' && board[i][j] != 'O'){
                    char tempValue = board[i][j];
                    board[i][j]='X';
                    //call recursively to choose best, negate max each time for each 'turn'
                    current_Best = (min( current_Best, minimax(depth+1, board, !maximize) ))+depth;
                    //reverse move to prev char
                    board[i][j] = tempValue;
                }
            }
        }
        return current_Best;
    }
}

char game_AI::bestMove(char board[3][3]){
    int bestVal = -10000;
    char bestIndex;
    //traverse board
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            //found empty spot
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                //save char value of spot
                char tempValue = board[i][j];
                //make an ai move
                board[i][j] = 'O';
                //evaluate the move
                int moveEval = minimax(0, board, false);
                //save best move
                if(moveEval>bestVal){
                    bestVal=moveEval;
                    bestIndex = tempValue;
                }
                //reverse move to prev char
                board[i][j] = tempValue;
            }
        }
    }
    return bestIndex;
}