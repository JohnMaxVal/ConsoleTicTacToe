#pragma once

#include "Board.hpp"

struct AIMove
{
    AIMove() = default;
    AIMove(int score) : score {score} {}
    
    int x;
    int y;
    int score;
};

class AIBot
{
public:
    void Init(char player);
    void SeachMove(Board& board);
private:
    AIMove GetBestMove(Board& board, char player);
    char ai;
    char human;
    const char no_val = ' ';
};