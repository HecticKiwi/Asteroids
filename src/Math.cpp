#include "Math.hpp"

std::mt19937& math::randomEngine() {
    static std::mt19937 mersenne{std::random_device{}()};
    return mersenne;
}

int math::randInt(int a, int b) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<> rand{a, b};
    return rand(randomEngine());
}

float math::randFloat(double a, double b) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<> rand{a, b};
    return rand(randomEngine());
}
