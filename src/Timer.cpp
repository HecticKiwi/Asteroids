#include "Timer.hpp"
#include "raylib.h"

Timer::Timer() { stop(); }

void Timer::start() {
    started = true;
    paused = false;

    startTicks = GetTime();
    pausedTicks = 0;
}

void Timer::stop() {
    started = false;
    paused = false;

    startTicks = 0;
    pausedTicks = 0;
}

void Timer::pause() {
    if (started && !paused) {
        paused = true;
        pausedTicks = GetTime() - startTicks;
        startTicks = 0;
    }
}

void Timer::resume() {
    if (started && paused) {
        paused = false;
        startTicks = GetTime() - pausedTicks;
        pausedTicks = 0;
    }
}

double Timer::getTime() {
    double time = 0;

    if (started) {
        if (paused) {
            time = pausedTicks;
        } else {
            time = GetTime() - startTicks;
        }
    }

    return time;
}

bool Timer::isStarted() { return started; }

bool Timer::isPaused() { return paused; }