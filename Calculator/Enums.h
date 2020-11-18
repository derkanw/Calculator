#pragma once

enum OperationType //determining the types of operations used
{
    Prefix, //e.g. sin(1)
    Postfix, //e.g. 1!
    Binary //e.g. 1 + 2
};

enum Priority //defining priority types for binary functions in descending order
{
    High,
    Medium,
    Low
};