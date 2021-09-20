#include "AIBot.hpp"
#include "Player.hpp"

enum class GameState
{
    RUN, EXIT
};

int main(int argc, char *argv[]) {
    char currentPlayer = 'X';
    char aiPlayer;

    std::cout << "Choose role: " << std::flush;
    char role;
    std::cin >> role;

    if(role == 'x' || role == 'X') {
        aiPlayer = 'O';
    }
    else if(role == 'o' || role == 'O') {
        aiPlayer = 'X';
    }

    AIBot ai;
    ai.Init(aiPlayer);
    Player player;
    Board* board = new Board();

    GameState state = GameState::RUN;

    while(state != GameState::EXIT) {
        board->Draw();

        if(currentPlayer == aiPlayer) {
            ai.SeachMove(*board);
        }
        else {
            std::cout << player << std::flush;
            std::cin >> player;
            std::tuple<int, int> pos = player.GetPosition();
            int x = std::get<0>(pos);
            int y = std::get<1>(pos);
            board->UpdateCell(x - 1, y - 1, currentPlayer);
        }

        char checkWin = board->CheckWin();
        if(checkWin != ' ') {
            board->Draw();
            if(checkWin == 'T') {
                std::cout << "Tie!" << std::endl;
            }
            else {
                if(currentPlayer == 'X') {
                    std::cout << "X player wins!" << std::endl;
                }
                else {
                    std::cout << "O player wins!" << std::endl;
                }
            }
            state = GameState::EXIT;
        }
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    delete board;

    return 0;
}