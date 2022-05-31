#include "Systems.hpp"
#include "Audio.hpp"
#include "Text.hpp"
#include "Textures.hpp"

int Systems::GAME_WIDTH = 800;
int Systems::GAME_HEIGHT = 450;

Text* Systems::text = new Text();
Audio* Systems::audio = new Audio();
Textures* Systems::textures = new Textures();

Systems::Systems() {}

Systems::~Systems() {
    delete text;
    delete audio;
    delete textures;
}

Audio* Systems::getAudio() { return audio; }

Text* Systems::getText() { return text; }

Textures* Systems::getTextures() { return textures; };