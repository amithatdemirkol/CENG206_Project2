#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
private:
    std::string name;
    int score;

public:
    Player(const std::string& playerName);

    std::string getName() const;
    int getScore() const;
    void increaseScore(int points);

    bool operator==(const Player& other) const;
};

#endif  // PLAYER_HPP

