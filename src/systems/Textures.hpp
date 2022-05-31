#pragma once

#include <vector>
#include "raylib.h"

class Textures
{
public:
    Textures();
    ~Textures();

    enum texture {
        SHIP,
    };

    Texture2D* getTexture(texture texture);

private:
    std::vector<Texture2D> textures;
};

