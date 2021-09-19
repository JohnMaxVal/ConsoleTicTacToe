#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <tuple>

class Board
{
public:
    void Draw();
    void Update(int x, int y);
    void NextPlayer();
    bool CheckWin();
    bool IsHumanTurn();

private:
    int GetColumn(int x, int y);
    bool CheckHorizontal();
    bool CheckVertical();
    bool CheckDiagonal();

private:
    char board[92] = 
    {
        '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+',
        '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|',
        '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+',
        '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|',
        '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+',
        '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|',
        '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+'
    };
    int coords[3][3] = {
        { 15, 19, 23 },
        { 41, 45, 49 },
        { 67, 71, 75 }
    };
    bool human {true};
    int countMoves {1};
    char currentMove {'X'};
};