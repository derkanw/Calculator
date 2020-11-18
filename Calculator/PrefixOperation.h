#pragma once
#include "BasicOperation.h"

class PrefixOperation : public BasicOperation //a class that combines the functionality of prefix operations
{
public:
    PrefixOperation();
    virtual ~PrefixOperation() = default;
};

PrefixOperation::PrefixOperation()
{
    type = OperationType::Prefix;
}