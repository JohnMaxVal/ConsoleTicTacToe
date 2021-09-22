#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <tuple>

class Board
{
public:
    Board() = default;

    void Draw();
    void UpdateCell(int x, int y, char value);
    char GetCellValue(int x, int y);
    char CheckWin();
    bool IsMovesLeft();

private:
    char board[91] = 
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
    char _currentPlayer;
    char _aiPlayer;
};