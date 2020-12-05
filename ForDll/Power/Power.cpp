#include "pch.h"
#include <utility>
#include <limits.h>
#include <cmath>
#include "Power.h"

Power::Power() : BasicOperation(OperationType::Binary)
{
    name = "^";
    priority = Priority::High;
}

double Power::Calculate(std::vector<double> numbers)
{
    return pow(numbers[0], numbers[1]);
}

BasicOperation* Load()
{
    return new Power;
}