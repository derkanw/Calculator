#pragma once
#include "../../Calculator/BasicOperation.h"

class Sinus : public BasicOperation
{
public:
    Sinus();

    double Calculate(std::vector<double> numbers);

    ~Sinus() = default;
};

extern "C" __declspec(dllexport) BasicOperation * Load();
