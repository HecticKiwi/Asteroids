#pragma once

#include <raylib.h>

class Entity
{
public:
    Entity();
    ~Entity();

    Vector2 getPos();
    float getRotation();
    float getRadius();

protected:
    void move();
    void checkScreenWrap();

    Vector2 pos, vel;
    float rotation;
    Texture2D* texture;
    float w, h;
    Vector2 origin;
    unsigned char alpha;
    float radius;
};

