#pragma once
#include "../../Calculator/BasicOperation.h"

class Exponent : public BasicOperation
{
public:
    Exponent();

    double Calculate(std::vector<double> numbers);

    ~Exponent() = default;
};

extern "C" __declspec(dllexport) BasicOperation * Load();

