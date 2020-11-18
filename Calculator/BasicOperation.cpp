#include "BasicOperation.h"

std::string BasicOperation::GetName()
{
    return name;
}

OperationType BasicOperation::GetType()
{
    return type;
}

Priority BasicOperation::GetPriority()
{
    return priority;
}