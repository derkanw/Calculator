#pragma once
#include "../../Calculator/BasicOperation.h"

class Cosinus : public BasicOperation
{
public:
    Cosinus();

    double Calculate(std::vector<double> numbers);

    ~Cosinus() = default;
};

extern "C" __declspec(dllexport) BasicOperation * Load();
