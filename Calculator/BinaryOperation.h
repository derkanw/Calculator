#pragma once
#include "BasicOperation.h"

class BinaryOperation : public BasicOperation //a class that combines the functionality of binary operations
{
public:
    BinaryOperation();
    virtual ~BinaryOperation() = default;
};

BinaryOperation::BinaryOperation()
{
    type = OperationType::Binary;
}