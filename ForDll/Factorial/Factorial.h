#pragma once
#include "../../Calculator/BasicOperation.h"

class Factorial : public BasicOperation
{
public:
    Factorial();

    double Calculate(std::vector<double> numbers);

    ~Factorial() = default;
};

extern "C" __declspec(dllexport) BasicOperation * Load();
