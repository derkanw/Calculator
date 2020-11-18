#pragma once
#include "../Calculator/BinaryOperation.h"

class Division : public BinaryOperation
{
public:
    Division();

    double Calculate(std::vector<double> numbers);

    ~Division() = default;
};

extern "C" __declspec(dllexport) BasicOperation* Load();
