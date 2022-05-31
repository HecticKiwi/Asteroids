#pragma once

#include "Timer.hpp"
#include "Entity.hpp"

class Bullet : public Entity
{
public:
    Bullet(Vector2 pos, float rotation);

    void update();
    void draw();
    bool isAlive();
    void kill();

private:
    bool alive;
    Timer life;
};

