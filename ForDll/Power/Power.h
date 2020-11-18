#pragma once
#include "../Calculator/BinaryOperation.h"

class Power : public BinaryOperation
{
public:
    Power();

    double Calculate(std::vector<double> numbers);

    ~Power() = default;
};

extern "C" __declspec(dllexport) BasicOperation* Load();