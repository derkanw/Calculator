#pragma once
#include "../Calculator/BinaryOperation.h"

class Multiplication : public BinaryOperation
{
public:
    Multiplication();

    double Calculate(std::vector<double> numbers);

    ~Multiplication() = default;
};

extern "C" __declspec(dllexport) BasicOperation* Load();