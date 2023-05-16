#include "HikeAndSeekGame.hpp"
#include <iostream>

HikeAndSeekGame::HikeAndSeekGame() {}

HikeAndSeekGame::~HikeAndSeekGame() {
    for (Player* player : players) {
        delete player;
    }
}

void HikeAndSeekGame::addPlayer(Player* player) {
    players.push_back(player);
}

void HikeAndSeekGame::playGame() {
    for (Player* player : players) {
        try {
            int foundItems = seekItems(player);
            player->increaseScore(foundItems);
            std::cout << player->getName() << " found " << foundItems << " items." << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "An error occurred: " << e.what() << std::endl;
        }
    }
}

int HikeAndSeekGame::seekItems(Player* player) throw(std::exception) {
    // Implementation for seeking items goes here
    // This is just a placeholder implementation
    if (player->getName() == "Alice") {
        throw std::runtime_error("Alice encountered an obstacle!");
    }
    return 3;  // Placeholder value for found items
}

