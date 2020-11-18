#include "pch.h"
#include <utility>
#include <limits.h>
#include "Exponent.h"

Exponent::Exponent() : PrefixOperation()
{
    name = "exp";
}

double Exponent::Calculate(std::vector<double> numbers)
{
    return exp(numbers[0]);
}

BasicOperation* Load()
{
    return new Exponent;
}