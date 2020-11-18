#pragma once
#include <string>
#include <vector>
#include "Enums.h"

class BasicOperation //base class of operations containing the main functionality
{
protected:
    std::string name; //type of record of operation in expression
    OperationType type; //operation type: binary, postfix, prefix
    Priority priority; //operation priority: high, medium, low

public:
    BasicOperation() = default;

    std::string GetName();
    OperationType GetType();
    Priority GetPriority();

    virtual double Calculate(std::vector<double> numbers) = 0;

    virtual ~BasicOperation() = default;
};