#include "Player.hpp"

Player::Player(const std::string& playerName) : name(playerName), score(0) {}

std::string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

void Player::increaseScore(int points) {
    score += points;
}

bool Player::operator==(const Player& other) const {
    return name == other.name && score == other.score;
}

