#include "Audio.hpp"

Audio::Audio() {
    InitAudioDevice();
    sounds.push_back(LoadSound("res/sfx/laserShoot.wav"));
    sounds.push_back(LoadSound("res/sfx/explosion.wav"));
}

Audio::~Audio() {
    for (auto& sound : sounds) { UnloadSound(sound); }
    CloseAudioDevice();
}

void Audio::playChunk(sound sound) {
    PlaySound(sounds[sound]);
}