#include "pch.h"
#include <utility>
#include <limits.h>
#include "Addition.h"

Addition::Addition() : BinaryOperation()
{
    name = "+";
    priority = Priority::Low;
}

double Addition::Calculate(std::vector<double> numbers)
{
    return numbers[0] + numbers[1];
}

BasicOperation* Load()
{
    return new Addition;
}