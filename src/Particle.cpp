#include <iostream>

#include "Particle.hpp"
#include "Math.hpp"

static constexpr double LIFETIME = 1;

Particle::Particle(Vector2 pos, float rotation)
{
    this->pos = pos;
    this->pos.x += cos(rotation*DEG2RAD) * 15;
    this->pos.y += sin(rotation*DEG2RAD) * 15;
    this->rotation = rotation + math::randFloat(-20, 20);
    alive = true;
    vel.x = cos(this->rotation*DEG2RAD) * 2;
    vel.y = sin(this->rotation*DEG2RAD) * 2;
    life.start();
    radius = 2;
}

void Particle::update() {
    move();
    alpha = (LIFETIME - life.getTime()) * 255.0 / LIFETIME;

    if (life.getTime() > LIFETIME) {
        alive = false;
    }
}

void Particle::draw() {
    DrawCircleV(pos, radius, {255, 255, 255, alpha});
}

bool Particle::isAlive() { return alive; }

void Particle::kill() { alive = false; }