#include "Board.hpp"
#include "AIBot.hpp"
#include "Player.hpp"

void Board::Draw() {
    for(int i = 0, j = 0; i < 91; ++i) {
        if(i != 0 && i % 13 == 0) { ++j; std::cout << "\n"; }
        std::cout << board[j * 13 + (i % 13)];
    }
    std::cout << "\n";
}

bool equals3(char c1, char c2, char c3) {
    return c1 == c2 && c2 == c3 && c1 != ' ';
}

char Board::CheckWin() {
    char winner = ' ';

    for(int i = 0; i < 3; ++i) {
        if(equals3(board[coords[i][0]], board[coords[i][1]], board[coords[i][2]])) {
            winner = board[coords[i][0]];
        }
    }
    for(int i = 0; i < 3; ++i) {
        if(equals3(board[coords[0][i]], board[coords[1][i]], board[coords[2][i]])) {
            winner = board[coords[0][i]];
        }
    }

    if(equals3(board[coords[0][0]], board[coords[1][1]], board[coords[2][2]])) {
        winner = board[coords[0][0]];
    }

    if(equals3(board[coords[2][0]], board[coords[1][1]], board[coords[0][2]])) {
        winner = board[coords[2][0]];
    }

    if(!IsMovesLeft()) {
        return 'T';
    }

    return winner;
}

void Board::UpdateCell(int x, int y, char value) {
    if((x < 0 || x > 3) || (y < 0 || y > 3)) {
        throw std::out_of_range("GetColumn: input is out of bound");
    }
    board[coords[y][x]] = value;
}

char Board::GetCellValue(int x, int y) {
    if((x < 0 || x > 3) || (y < 0 || y > 3)) {
        throw std::out_of_range("GetColumn: input is out of bound");
    }
    return board[coords[y][x]];
}

bool Board::IsMovesLeft() {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(board[coords[i][j]] == ' ') {
                return true;
            }
        }
    }
    return false;
}