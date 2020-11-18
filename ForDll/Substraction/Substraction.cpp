#include "pch.h"
#include <utility>
#include <limits.h>
#include "Substraction.h"

Substraction::Substraction() : BinaryOperation()
{
    name = "-";
    priority = Priority::Low;
}

double Substraction::Calculate(std::vector<double> numbers)
{
    return numbers[0] - numbers[1];
}

BasicOperation* Load()
{
    return new Substraction;
}