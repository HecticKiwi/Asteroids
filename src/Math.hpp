#pragma once

#include <random>

namespace math {
    std::mt19937& randomEngine();
    int randInt(int a, int b);
    float randFloat(double a, double b);
}