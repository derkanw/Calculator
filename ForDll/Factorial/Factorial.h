#pragma once
#include "../Calculator/PostfixOperation.h"

class Factorial : public PostfixOperation
{
public:
    Factorial();

    double Calculate(std::vector<double> numbers);

    ~Factorial() = default;
};

extern "C" __declspec(dllexport) BasicOperation * Load();
