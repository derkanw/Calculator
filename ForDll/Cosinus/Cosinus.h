#pragma once
#include "../../Calculator/PrefixOperation.h"

class Cosinus : public PrefixOperation
{
public:
    Cosinus();

    double Calculate(std::vector<double> numbers);

    ~Cosinus() = default;
};

extern "C" __declspec(dllexport) BasicOperation * Load();
