#include "Board.hpp"

void Board::Draw() {
    for(int i = 0, j = 0; i < 91; ++i) {
        if(i != 0 && i % 13 == 0) { ++j; std::cout << "\n"; }
        std::cout << board[j * 13 + (i % 13)];
    }
    std::cout << "\n";
}

int Board::GetColumn(int x, int y) {
    return coords[x-1][y-1];
    //return 26 * (x-1) + 15 + 4 * (y-1);
}

void Board::Update(int x, int y) {
    if((x < 0 || x > 3) || (y < 0 || y > 3)) {
        throw std::out_of_range("GetColumn: input is out of bound");
    }
    int columnToUpdate = GetColumn(x, y);
    board[columnToUpdate] = currentMove;
}

void Board::NextPlayer() {
    human = !human;
    currentMove = (human) ? 'X' : 'O';
}

bool Board::CheckWin() {
    return CheckHorizontal() || CheckVertical() || CheckDiagonal();
}

bool Board::IsHumanTurn() {
    return human;
}

bool equals3(char c1, char c2, char c3) {
    return c1 == c2 && c2 == c3 && c1 != ' ';
}

bool Board::CheckHorizontal() {
    for(int i = 0; i < 3; ++i) {
        if(!equals3(board[coords[i][0]], board[coords[i][1]], board[coords[i][2]])) {
            return false;
        }
    }
    // for(int col = 0; col < 3; ++col) {
    //     int winPoint = 0;
    //     for(int row = 0; row < 3; ++row, ++winPoint) {
    //         if(board[coords[row][col]] != currentMove) {
    //             break;
    //         }
    //     }
    //     if(winPoint == 3) {
    //         return true;
    //     }
    // }
    return true;
}

bool Board::CheckVertical() {
    for(int i = 0; i < 3; ++i) {
        if(!equals3(board[coords[0][i]], board[coords[1][i]], board[coords[2][i]])) {
            return false;
        }
    }
    return true;
    // for(int col = 0; col < 3; ++col) {
    //     int winPoint = 0;
    //     for(int row = 0; row < 3; ++row, ++winPoint) {
    //         if(board[coords[col][row]] != currentMove) {
    //             break;
    //         }
    //     }
    //     if(winPoint == 3) {
    //         return true;
    //     }
    // }
    // return false;
}

bool Board::CheckDiagonal() {
    bool check = true;
    for(int row = 0, col = 0; row < 3 && col < 3; ++row, ++col) {// check right diagonal
        if(board[coords[row][col]] != currentMove) {
            check = false;
            break;
        }
    }

    if(check) return true;

    check = true;
    for(int row = 2, col = 0; row >= 0, col < 3; --row, ++col) { // check left diagonal
        if(board[coords[row][col]] != currentMove) {
            check = false;
            break;
        }
    }

    return check;
}