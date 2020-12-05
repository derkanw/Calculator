#pragma once
#include "../../Calculator/BasicOperation.h"

class Division : public BasicOperation
{
public:
    Division();

    double Calculate(std::vector<double> numbers);

    ~Division() = default;
};

extern "C" __declspec(dllexport) BasicOperation* Load();
