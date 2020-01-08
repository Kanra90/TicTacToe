#ifndef BOARD_H
#define BOARD_H
class board{
    public:
        char board[3][3] = { '1','2','3','4','5','6','7','8','9'};
        int turnClock = 0;
        char player = 'X';
        char ai = 'O';
        void input();
        char printBoard();
        char checkWin();
        bool movesLeft();
        bool isEmpty(int,int);
        char blankSpotValue(int, int);
        void move(int, int);
        void move_AI(char);
};
#endif