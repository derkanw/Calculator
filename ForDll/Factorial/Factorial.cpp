#include "pch.h"
#include <utility>
#include <limits.h>
#include "Factorial.h"

Factorial::Factorial() : PostfixOperation()
{
    name = "!";
}

double Factorial::Calculate(std::vector<double> numbers)
{
    int result = 1;

    if (round(numbers[0]) == 0)
        return result;

    for (unsigned int i = 1; i <= round(numbers[0]); i++)
        result *= i;

    return result;
}

BasicOperation* Load()
{
    return new Factorial;
}