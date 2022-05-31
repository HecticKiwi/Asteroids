#include "Game.hpp"
#include "raylib.h"
#include "Player.hpp"
#include "Asteroid.hpp"
#include "Particle.hpp"
#include "Math.hpp"
#include "systems/Systems.hpp"

#include <vector>
#include <algorithm>
#include <string>

Game::Game()
{
    reset();
    GameLoop();
}

void Game::reset() {
    player = Player(Systems::GAME_WIDTH/2.0, Systems::GAME_HEIGHT/2.0);
    bullets.clear();
    particles.clear();
    asteroids.clear();
    for (int i = 0; i < 4; i++) {
        asteroids.emplace_back(Vector2{300, 300}, Asteroid::LARGE);
    }
    state = PLAYING;
}

void Game::GameLoop() {
    while (!WindowShouldClose()) {
        update();
        draw();
    }
}

void Game::update() {
    switch (state) {
        case PLAYING: {
            if (IsKeyPressed(KEY_SPACE)) {
                bullets.emplace_back(player.getPos(), player.getRotation()); 
                Systems::getAudio()->playChunk(Audio::LASER_SHOOT);
            }
            if (IsKeyDown(KEY_UP)) { particles.emplace_back(player.getPos(), player.getRotation() + 180); }
            
            player.update();
            for (auto& asteroid : asteroids) {
                if (CheckCollisionCircles(player.getPos(), player.getRadius(), asteroid.getPos(), asteroid.getRadius())) {
                    state = GAME_OVER;
                }
            }

            for (auto& particle : particles) { particle.update(); }

            std::vector<Asteroid> newAsteroids;
            for (auto& bullet : bullets) {
                bullet.update();
                for (auto& asteroid : asteroids) {
                    if (CheckCollisionCircles(bullet.getPos(), bullet.getRadius(), asteroid.getPos(), asteroid.getRadius())) {
                        bullet.kill();
                        asteroid.kill();
                        if (asteroid.getType() == Asteroid::LARGE) {
                            for (int i = 0; i < 2; i++) {
                                newAsteroids.emplace_back(asteroid.getPos(), Asteroid::MEDIUM);
                            }
                        } else if (asteroid.getType() == Asteroid::MEDIUM) {
                            for (int i = 0; i < 3; i++) {
                                newAsteroids.emplace_back(asteroid.getPos(), Asteroid::SMALL);
                            }
                        }
                        for (int i = 0; i < 10; i++) {
                            particles.emplace_back(asteroid.getPos(), math::randFloat(0, 360));
                        }
                        Systems::getAudio()->playChunk(Audio::EXPLOSION);
                    }
                }
            }
            asteroids.insert(asteroids.end(), newAsteroids.begin(), newAsteroids.end());

            for (auto& asteroid : asteroids) { asteroid.update(); }

            particles.erase(std::remove_if(particles.begin(), particles.end(), [](Particle& particle) { return !particle.isAlive(); }), particles.end());
            bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet& bullet) { return !bullet.isAlive(); }), bullets.end());
            asteroids.erase(std::remove_if(asteroids.begin(), asteroids.end(), [](Asteroid& asteroid) { return !asteroid.isAlive(); }), asteroids.end());
            break;
        }
        case GAME_OVER: {
            if (IsKeyPressed(KEY_ENTER)) {
                reset();
            }
            break;
        }
    }
}

void Game::draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    switch (state) {
        case PLAYING: {
            int asteroidsLeft = asteroids.size();
            std::string text;
            if (asteroidsLeft == 0) {
                renderTextCenter("You win!");
            } else {
                renderTextCenter("Asteroids left: " + std::to_string(asteroidsLeft));
            }
            int textWidth = MeasureText(text.c_str(), 20);
            DrawText(text.c_str(), Systems::GAME_WIDTH/2 - textWidth/2, 200, 20, WHITE);

            for (auto& particle : particles) { particle.draw(); }
            for (auto& bullet : bullets) { bullet.draw(); }
            for (auto& asteroid : asteroids) { asteroid.draw(); }
            player.draw();
            break;
        }
        case GAME_OVER: {
            renderTextCenter("You died. Press [ENTER] to play again");
            break;
        }
    }

    EndDrawing();
}

void Game::renderTextCenter(std::string string) {
    int textWidth = MeasureText(string.c_str(), 20);
    DrawText(string.c_str(), Systems::GAME_WIDTH/2 - textWidth/2, 200, 20, WHITE);
}

Game::~Game() {}