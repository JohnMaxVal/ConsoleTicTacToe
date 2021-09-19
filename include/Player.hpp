#pragma once

#include "Board.hpp"

class Player
{
public:
    std::tuple<int, int> GetPosition();

private:
    int m_xPos;
    int m_yPos;

friend std::ostream& operator<<(std::ostream& os, const Player& player);
friend std::istream& operator>>(std::istream& is, Player& player);
};