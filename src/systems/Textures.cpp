#include "Textures.hpp"
#include "Systems.hpp"

Textures::Textures() {
    InitWindow(Systems::GAME_WIDTH, Systems::GAME_HEIGHT, "Asteroids");
    textures.push_back(LoadTexture("res/gfx/ship_G.png"));
    SetTargetFPS(60);
}

Textures::~Textures() {
    for (auto& texture : textures) { UnloadTexture(texture); }
    CloseWindow();
}

Texture2D* Textures::getTexture(texture texture) {
    return &textures[texture];
}