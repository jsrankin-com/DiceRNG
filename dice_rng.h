#pragma once
#include <random>
#include <vector>

class DiceRNG {
private:
    std::random_device device;
    std::mt19937 generator;
    std::uniform_int_distribution<int> distribution;

public:
    DiceRNG();
    ~DiceRNG() = default;

    int operator()();
    std::vector<int> operator()(int);

    int Roll();
    std::vector<int> Roll(int);
};
