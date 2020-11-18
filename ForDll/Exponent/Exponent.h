#pragma once
#include "../Calculator/PrefixOperation.h"

class Exponent : public PrefixOperation
{
public:
    Exponent();

    double Calculate(std::vector<double> numbers);

    ~Exponent() = default;
};

extern "C" __declspec(dllexport) BasicOperation * Load();

