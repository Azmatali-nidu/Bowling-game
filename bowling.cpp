// BowlingGame.cpp
#include "BowlingGame.h"
#include <stdexcept>

BowlingGame::BowlingGame() : currentFrameIndex(0) {
    frames.reserve(10);
    for (int i = 0; i < 10; ++i) {
        frames.emplace_back(i == 9);
    }
}

void BowlingGame::roll(int pins) {
    if (currentFrameIndex >= 10) {
        throw std::logic_error("All frames are already complete.");
    }

    Frame& currentFrame = frames[currentFrameIndex];
    currentFrame.addRoll(pins);

    if (currentFrame.isComplete() && currentFrameIndex < 9) {
        ++currentFrameIndex;
    }
}

int BowlingGame::score() const {
    int totalScore = 0;
    for (size_t i = 0; i < frames.size(); ++i) {
        const Frame& frame = frames[i];
        totalScore += frame.getScore();

        if (frame.isStrike() && i < 9) {
            // Add next two rolls
            int bonus = 0;
            if (frames[i + 1].getRolls().size() >= 1) {
                bonus += frames[i + 1].getRoll(0);
                if (frames[i + 1].getRolls().size() >= 2) {
                    bonus += frames[i + 1].getRoll(1);
                } else if (i + 2 < frames.size()) {
                    bonus += frames[i + 2].getRoll(0);
                }
            }
            totalScore += bonus;
        } else if (frame.isSpare() && i < 9) {
            // Add next one roll
            if (frames[i + 1].getRolls().size() >= 1) {
                totalScore += frames[i + 1].getRoll(0);
            }
        }
    }
    return totalScore;
}
