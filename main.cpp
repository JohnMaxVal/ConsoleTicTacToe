#include "Player.hpp"

int main(int argc, char *argv[]) {
    Board* board = new Board;
    Player player;
    board->Draw();

    int state = 0;

    while(true) {
        std::cout << player;
        std::cin >> player;

        auto inputPosition = player.GetPosition();

        board->Update(
            std::get<0>(inputPosition), 
            std::get<1>(inputPosition));
        board->Draw();

        if(board->CheckWin()) {
            std::string winOrLoose = board->IsHumanTurn() ? "win" : "loose";
            std::cout << "You " << winOrLoose << std::endl;
            break;
        }

        board->NextPlayer();

        
    }

    delete board;

    return 0;
}