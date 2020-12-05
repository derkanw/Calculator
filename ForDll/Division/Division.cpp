#include "pch.h"
#include <utility>
#include <limits.h>
#include "Division.h"

Division::Division() : BasicOperation(OperationType::Binary)
{
    name = "/";
    priority = Priority::Medium;
}

double Division::Calculate(std::vector<double> numbers)
{
    return numbers[0] / numbers[1];
}

BasicOperation* Load()
{
    return new Division;
}