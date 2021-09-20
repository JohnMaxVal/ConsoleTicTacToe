#include "AIBot.hpp"

#include <limits>
#include <algorithm>
#include <map>
#include <vector>

void AIBot::Init(char player) {
    ai = player;
    human = (ai == 'X') ? 'O' : 'X';
}

void AIBot::SeachMove(Board& board) {
    AIMove bestMove = GetBestMove(board, ai);
    board.UpdateCell(bestMove.x, bestMove.y, ai);
}

AIMove AIBot::GetBestMove(Board& board, char player) {
    char winner = board.CheckWin();
    
    if(winner == ai) {
        return AIMove(10);
    }
    else if(winner == human) {
        return AIMove(-10);
    }
    else if(winner == 'T') {
        return AIMove(0);
    }

    std::vector<AIMove> moves;

    for(int row = 0; row < 3; ++row) {
        for(int col = 0; col < 3; ++col) {
            if(board.GetCellValue(col, row) == no_val) {
                AIMove aiMove;
                aiMove.x = col;
                aiMove.y = row;
                board.UpdateCell(col, row, player);
                if(player == ai) {
                    aiMove.score = GetBestMove(board, human).score;
                }
                else {
                    aiMove.score = GetBestMove(board, ai).score;
                }
                moves.push_back(aiMove);
                board.UpdateCell(col, row, no_val);
            }
        }
    }

    int bestMove = 0;
    if(player == ai) {
        int bestScore = std::numeric_limits<int>::min();
        for(int i = 0; i < moves.size(); ++i) {
            if(moves[i].score > bestScore) {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    else {
        int bestScore = std::numeric_limits<int>::max();
        for(int i = 0; i < moves.size(); ++i) {
            if(moves[i].score < bestScore) {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    return moves[bestMove];
}