#include "Player.hpp"

std::tuple<int, int> Player::GetPosition() {
    return std::tuple<int, int> {m_xPos, m_yPos};
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Enter position: ";
    return os;
}

std::istream& operator>>(std::istream& is, Player& player) {
    is >> player.m_xPos;
    is >> player.m_yPos;
    return is;
}