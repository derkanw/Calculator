#pragma once
#include "../../Calculator/BasicOperation.h"

class Substraction : public BasicOperation
{
public:
    Substraction();

    double Calculate(std::vector<double> numbers);

    ~Substraction() = default;
};

extern "C" __declspec(dllexport) BasicOperation* Load();