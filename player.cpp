// Player.cpp
#include "Player.h"

Player::Player(const std::string& playerName) : name(playerName) {}

std::string Player::getName() const {
    return name;
}
