#pragma once
#include "../../Calculator/PrefixOperation.h"

class Logarithm : public PrefixOperation
{
public:
    Logarithm();

    double Calculate(std::vector<double> numbers);

    ~Logarithm() = default;
};

extern "C" __declspec(dllexport) BasicOperation * Load();
