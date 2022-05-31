#include "Player.hpp"
#include <cmath>

#include "systems/Systems.hpp"
#include "systems/Audio.hpp"

static constexpr float PLAYER_SPEED = 0.3f;
static constexpr float ROTATION_SPEED = 5.0f;

Player::Player(float x, float y) {
    pos = {x, y};
    vel = {0, 0};
    rotation = 0;
    this->texture = Systems::getTextures()->getTexture(Textures::SHIP);
    w = texture->width;
    h = texture->height;
    origin = {w/2.0f, h/2.0f};
    radius = this->texture->width / 2.0;
}

void Player::update() {
    if (IsKeyDown(KEY_LEFT)) rotation -= ROTATION_SPEED;
    if (IsKeyDown(KEY_RIGHT)) rotation += ROTATION_SPEED;
    if (IsKeyDown(KEY_UP)) {
        vel.x += std::cos(rotation*DEG2RAD) * PLAYER_SPEED;
        vel.y += std::sin(rotation*DEG2RAD) * PLAYER_SPEED;
    }

    move();
    checkScreenWrap();

    vel.x *= 0.975;
    vel.y *= 0.975;
}

void Player::draw() {
    Rectangle srcRect = {0.0f, 0.0f, w, h};
    Rectangle destRect = {pos.x, pos.y, w, h};
    
    DrawTexturePro(*texture, srcRect, destRect, origin, rotation, WHITE);
}