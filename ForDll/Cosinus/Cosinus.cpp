#include "pch.h"
#include <utility>
#include <limits.h>
#include "Cosinus.h"

Cosinus::Cosinus() : PrefixOperation()
{
    name = "cos";
}

double Cosinus::Calculate(std::vector<double> numbers)
{
    return cos(numbers[0]);
}

BasicOperation* Load()
{
    return new Cosinus;
}