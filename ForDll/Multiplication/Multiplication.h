#pragma once
#include "../../Calculator/BasicOperation.h"

class Multiplication : public BasicOperation
{
public:
    Multiplication();

    double Calculate(std::vector<double> numbers);

    ~Multiplication() = default;
};

extern "C" __declspec(dllexport) BasicOperation* Load();