#pragma once

#include "raylib.h"
#include "Timer.hpp"
#include "Entity.hpp"

class Particle : public Entity
{
public:
    Particle(Vector2 pos, float rotation);
    void update();
    void draw();
    bool isAlive();
    void kill();

private:
    bool alive;
    Timer life;
};