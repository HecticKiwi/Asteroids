#pragma once

class Timer
{
public:
    Timer();

    void start();
    void stop();
    void pause();
    void resume();

    double getTime();

    bool isStarted();
    bool isPaused();
private:
    double startTicks;
    double pausedTicks;

    bool started;
    bool paused;
};