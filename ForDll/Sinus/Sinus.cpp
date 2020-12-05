#include "pch.h"
#include <utility>
#include <limits.h>
#include "Sinus.h"

Sinus::Sinus() : BasicOperation(OperationType::Prefix)
{
    name = "sin";
}

double Sinus::Calculate(std::vector<double> numbers)
{
    return sin(numbers[0]);
}

BasicOperation* Load()
{
    return new Sinus;
}