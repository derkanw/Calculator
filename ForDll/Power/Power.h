#pragma once
#include "../../Calculator/BasicOperation.h"

class Power : public BasicOperation
{
public:
    Power();

    double Calculate(std::vector<double> numbers);

    ~Power() = default;
};

extern "C" __declspec(dllexport) BasicOperation* Load();