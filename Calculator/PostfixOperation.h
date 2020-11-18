#pragma once
#include "BasicOperation.h"

class PostfixOperation : public BasicOperation //a class that combines the functionality of postfix operations
{
public:
    PostfixOperation();
    virtual ~PostfixOperation() = default;
};

PostfixOperation::PostfixOperation()
{
    type = OperationType::Postfix;
}