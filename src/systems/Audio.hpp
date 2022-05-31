#pragma once

#include "raylib.h"
#include <vector>

class Audio
{
public:
    Audio();
    ~Audio();

    enum sound {
        LASER_SHOOT,
        EXPLOSION,
    };

    void playChunk(sound sound);

private:
    std::vector<Music> musics;
    std::vector<Sound> sounds;
};