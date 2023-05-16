#ifndef HIKE_AND_SEEK_GAME_HPP
#define HIKE_AND_SEEK_GAME_HPP

#include <vector>
#include <exception>
#include "Player.hpp"

class HikeAndSeekGame {
private:
    std::vector<Player*> players;

public:
    HikeAndSeekGame();
    ~HikeAndSeekGame();

    void addPlayer(Player* player);
    void playGame();

private:
    int seekItems(Player* player) throw(std::exception);
};

#endif  // HIKE_AND_SEEK_GAME_HPP

