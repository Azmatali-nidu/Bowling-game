// Frame.cpp
#include "Frame.h"
#include <stdexcept>

Frame::Frame(bool tenth) : isTenthFrame(tenth) {}

void Frame::addRoll(int pins) {
    if (pins < 0 || pins > 10) {
        throw std::invalid_argument("Invalid number of pins.");
    }
    rolls.push_back(pins);
}

int Frame::getRoll(int index) const {
    if (index < 0 || index >= rolls.size()) {
        throw std::out_of_range("Roll index out of range.");
    }
    return rolls[index];
}

int Frame::getScore() const {
    int sum = 0;
    for (int pins : rolls) {
        sum += pins;
    }
    return sum;
}

bool Frame::isStrike() const {
    return !rolls.empty() && rolls[0] == 10;
}

bool Frame::isSpare() const {
    return rolls.size() >= 2 && (rolls[0] + rolls[1] == 10) && !isStrike();
}

bool Frame::isComplete() const {
    if (isTenthFrame) {
        if (rolls.size() < 2) return false;
        if (rolls.size() == 2) {
            return (rolls[0] + rolls[1] < 10);
        }
        return rolls.size() == 3;
    } else {
        return isStrike() || rolls.size() == 2;
    }
}

const std::vector<int>& Frame::getRolls() const {
    return rolls;
}
