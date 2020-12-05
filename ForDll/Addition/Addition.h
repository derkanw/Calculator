#pragma once
#include "../../Calculator/BasicOperation.h"

class Addition : public BasicOperation
{
public:
    Addition();

    double Calculate(std::vector<double> numbers);
    
    ~Addition() = default;
};

extern "C" __declspec(dllexport) BasicOperation* Load();