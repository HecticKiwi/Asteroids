#include <iostream>

#include "Bullet.hpp"
#include "Math.hpp"

static constexpr double LIFETIME = 1;

Bullet::Bullet(Vector2 pos, float rotation)
{
    this->pos = pos;
    this->rotation = rotation;
    this->pos.x += cos(this->rotation*DEG2RAD) * 15;
    this->pos.y += sin(this->rotation*DEG2RAD) * 15;
    vel.x = cos(this->rotation*DEG2RAD) * 5;
    vel.y = sin(this->rotation*DEG2RAD) * 5;
    radius = 3;
    alive = true;
    life.start();
}

void Bullet::update() {
    move();
    checkScreenWrap();

    if (life.getTime() > LIFETIME) {
        alive = false;
    }
}

void Bullet::draw() {
    DrawCircleV(pos, radius, RED);
}

bool Bullet::isAlive() { return alive; }

void Bullet::kill() { alive = false; }