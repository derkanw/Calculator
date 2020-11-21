#pragma once
#include "../../Calculator/BinaryOperation.h"

class Substraction : public BinaryOperation
{
public:
    Substraction();

    double Calculate(std::vector<double> numbers);

    ~Substraction() = default;
};

extern "C" __declspec(dllexport) BasicOperation* Load();