#pragma once
#include "../../Calculator/BasicOperation.h"

class Logarithm : public BasicOperation
{
public:
    Logarithm();

    double Calculate(std::vector<double> numbers);

    ~Logarithm() = default;
};

extern "C" __declspec(dllexport) BasicOperation * Load();
