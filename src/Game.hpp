#pragma once

#include <vector>
#include <string>
#include "Player.hpp"
#include "Asteroid.hpp"
#include "Particle.hpp"
#include "Bullet.hpp"

class Game
{
public:
    Game();
    ~Game();
    
private:
    void GameLoop();
    void update();
    void draw();
    void reset();
    void renderTextCenter(std::string string);

    enum state {
        PLAYING,
        GAME_OVER,
    };

    state state;

    Player player;
    std::vector<Asteroid> asteroids;
    std::vector<Particle> particles;
    std::vector<Bullet> bullets;
};

