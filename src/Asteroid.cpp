#include "raylib.h"
#include "Asteroid.hpp"
#include "Math.hpp"
#include <cmath>

Asteroid::Asteroid(Vector2 pos, TYPE type) {
    this->pos = pos;
    this->type = type;
    active = true;
    if (type == LARGE) {
        radius = 20;
        speed = 1;
    } else if (type == MEDIUM) {
        radius = 15;
        speed = 1.35;
    } else if (type == SMALL) {
        radius = 10;
        speed = 2;
    }
    rotation = math::randFloat(0, 360);
    vel.x = cos(this->rotation*DEG2RAD) * speed;
    vel.y = sin(this->rotation*DEG2RAD) * speed;
}

void Asteroid::update() {
    move();
    checkScreenWrap();
}

void Asteroid::draw() {
    DrawCircleV(pos, radius, LIGHTGRAY);
}

bool Asteroid::isAlive() {
    return active;
}

void Asteroid::kill() {
    active = false;
}

int Asteroid::getType() { return type; }