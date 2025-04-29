// BowlingGame.h
#pragma once
#include <vector>
#include "Frame.h"

class BowlingGame {
private:
    std::vector<Frame> frames;
    int currentFrameIndex;
public:
    BowlingGame();
    void roll(int pins);
    int score() const;
};
