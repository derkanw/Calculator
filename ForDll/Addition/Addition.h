#pragma once
#include "../../Calculator/BinaryOperation.h"

class Addition : public BinaryOperation
{
public:
    Addition();

    double Calculate(std::vector<double> numbers);
    
    ~Addition() = default;
};

extern "C" __declspec(dllexport) BasicOperation* Load();