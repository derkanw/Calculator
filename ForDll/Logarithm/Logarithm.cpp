#include "pch.h"
#include <utility>
#include <limits.h>
#include "Logarithm.h"

Logarithm::Logarithm() : BasicOperation(OperationType::Prefix)
{
    name = "ln";
}

double Logarithm::Calculate(std::vector<double> numbers)
{
    return log(numbers[0]);
}

BasicOperation* Load()
{
    return new Logarithm;
}