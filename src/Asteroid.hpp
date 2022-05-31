#pragma once

#include "raylib.h"
#include "Entity.hpp"

class Asteroid : public Entity
{
public:
    enum TYPE {
        LARGE,
        MEDIUM, 
        SMALL
    };

    Asteroid(Vector2 pos, TYPE type);
    ~Asteroid() {}

    void update();
    void draw();
    bool isAlive();
    void kill();

    int getType();

private:
    bool active;
    TYPE type;
    float speed;
};

