#pragma once

#include "raylib.h"
#include "Entity.hpp"

class Player : public Entity
{
public:
    Player() {}
    Player(float x, float y);
    ~Player() {}
    
    void update();
    void draw();

private:
};