#pragma once
#include "../Calculator/PrefixOperation.h"

class Sinus : public PrefixOperation
{
public:
    Sinus();

    double Calculate(std::vector<double> numbers);

    ~Sinus() = default;
};

extern "C" __declspec(dllexport) BasicOperation * Load();
