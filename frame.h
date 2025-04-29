// Frame.h
#pragma once
#include <vector>

class Frame {
private:
    std::vector<int> rolls;
    bool isTenthFrame;
public:
    Frame(bool tenth = false);
    void addRoll(int pins);
    int getRoll(int index) const;
    int getScore() const;
    bool isStrike() const;
    bool isSpare() const;
    bool isComplete() const;
    const std::vector<int>& getRolls() const;
};
