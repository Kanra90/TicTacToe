#ifndef GAME_AI_H
#define GAME_AI_H
class game_AI{
    public:
        int evaluate(char [3][3]);
        int minimax(int, char [3][3],bool);
        char bestMove(char[3][3]);
        bool movesLeft(char board[3][3]);
};
#endif