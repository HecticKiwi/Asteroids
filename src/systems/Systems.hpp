#pragma once

#include "Text.hpp"
#include "Audio.hpp"
#include "Textures.hpp"

class Systems
{
public:
    Systems();
    ~Systems();

    static int GAME_WIDTH, GAME_HEIGHT;

    static Audio* getAudio();
    static Text* getText();
    static Textures* getTextures();

private:
    static Audio* audio;
    static Text* text;
    static Textures* textures;
};