#include "Entity.hpp"
#include "systems/Systems.hpp"

Entity::Entity() {}

Entity::~Entity() {}

void Entity::move() {
    pos.x += vel.x;
    pos.y += vel.y;
}

void Entity::checkScreenWrap() {
    if (pos.x + radius < 0) {
        pos.x += Systems::GAME_WIDTH + radius*2;
    }
    if (pos.x - radius > Systems::GAME_WIDTH) {
        pos.x -= Systems::GAME_WIDTH + radius*2;
    }
    if (pos.y - radius > Systems::GAME_HEIGHT) {
        pos.y -= Systems::GAME_HEIGHT + radius*2;
    }
    if (pos.y + radius < 0) {
        pos.y += Systems::GAME_HEIGHT + radius*2;
    }
}

float Entity::getRotation() { return rotation; }

Vector2 Entity::getPos() { return pos; }

float Entity::getRadius() { return radius; }