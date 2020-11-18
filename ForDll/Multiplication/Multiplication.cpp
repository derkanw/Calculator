#include "pch.h"
#include <utility>
#include <limits.h>
#include "Multiplication.h"

Multiplication::Multiplication() : BinaryOperation()
{
    name = "*";
    priority = Priority::Medium;
}

double Multiplication::Calculate(std::vector<double> numbers)
{
    return numbers[0] * numbers[1];
}

BasicOperation* Load()
{
    return new Multiplication;
}