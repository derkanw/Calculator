#include "Calculator.h"

void Calculator::Split(void) //dividing the input string into logical units
{
    size_t start = 0;
    std::string separator = " ";

    size_t end = expression.find(separator);

    while (end != std::string::npos)
    {
        parts.push_back(expression.substr(start, end - start));
        start = end + separator.length();
        end = expression.find(separator, start);
    }

    parts.push_back(expression.substr(start, end));
}

bool Calculator::IsDigit(std::string part) //checking that the logical unit of the expression is an integer or decimal number
{
    if (part.empty())
        return false;

    for (char symbol : part)
        if (!isdigit(symbol) && symbol != '.')
            return false;
    return true;
}

BasicOperation* Calculator::GetOperation(std::string part) //returns the corresponding operation by the given value
{
    if (part.empty())
        return nullptr;

    for (BasicOperation* operation : operations)
        if (operation->GetName() == part)
            return operation;

    return nullptr;
}

bool Calculator::IsCorrect(void) //checking that the given line has the same number of '(' and ')'
{
    unsigned int countOpening = 0, countClosing = 0;

    for (std::string part : parts)
    {
        if (part == "(")
            countOpening++;
        if (part == ")")
            countClosing++;
    }

    return !parts.empty() && countOpening == countClosing;
}

bool Calculator::IsCorrectType(std::string part, OperationType type) //checking if the type of the operation matches the given type
{
    BasicOperation* operation = GetOperation(part);
    return operation != nullptr && operation->GetType() == type;
}

bool Calculator::IsHigherPriority(std::string part1, std::string part2) //checking that the first operation has a higher priority
{
    BasicOperation* op1 = GetOperation(part1);
    BasicOperation* op2 = GetOperation(part2);
    
    return op1 != nullptr && op2 != nullptr && op1->GetPriority() <= op2->GetPriority();
}

bool Calculator::HasOpeningBracket(void) //checking the correct position of the brackets
{
    for (std::string part : stack)
        if (part == "(")
            return true;
        return false;
}

bool Calculator::DigitOrPostfix(std::string part) //numbers and postfix operations are added directly to the reverse polish notation
{
    if (IsDigit(part) || IsCorrectType(part, OperationType::Postfix))
    {
        notation.push_back(part);
        return true;
    }
    return false;
}

bool Calculator::LBracketOrPrefix(std::string part) //left brackets and prefix operations are added immediately to the stack entry
{
    if (part == "(" || IsCorrectType(part, OperationType::Prefix))
    {
        stack.push_back(part);
        return true;
    }
    return false;
}

bool Calculator::RBracket(std::string part) //when a right bracket appears, all stack elements up to the left bracket are unloaded
{
    if (part == ")")
    {
        if (!HasOpeningBracket())
        {
            std::cout << "Syntax error" << std::endl;
            return true;
        }

        while (!stack.empty() && stack.back() != "(")
        {
            notation.push_back(stack.back());
            stack.pop_back();
        }

        if (!stack.empty())
            stack.pop_back();
        return true;
    }
    return false;
}

bool Calculator::Binary(std::string part) //binary operations are written according to the priority of the operations
{
    if (IsCorrectType(part, OperationType::Binary))
    {
        if (stack.empty())
        {
            stack.push_back(part);
            return true;
        }

        while (!stack.empty() && (IsCorrectType(stack.back(), OperationType::Prefix) || IsHigherPriority(stack.back(), part)))
        {
            notation.push_back(stack.back());
            stack.pop_back();
        }
        stack.push_back(part);
        return true;
    }
    return false;
}

void Calculator::PushRemainder(void) //writing the remaining elements of the stack to the reverse polish notation
{
    size_t size = stack.size();
    for (unsigned int i = 0; i < size; i++)
    {
        notation.push_back(stack.back());
        stack.pop_back();
    }
}

void Calculator::PolishNotation(void) //converting the input string according to the reverse polish notation algorithm
{
    if (expression.empty() || operations.empty())
    {
        std::cout << "Invalid expression" << std::endl;
        return;
    }

    for (std::string part : parts)
        if (!(DigitOrPostfix(part) || LBracketOrPrefix(part) || RBracket(part) || Binary(part)))
        {
            std::cout << "Invalid operation" << std::endl;
            return;
        }

    PushRemainder();
}

double Calculator::StackMachine(void) //calculating the result of the entered expression in the reverse polish notation algorithm
{
    for (std::string part : notation)
    {
        if (IsDigit(part))
            resultStack.push_back(part);
        else
        {
            double result;
            size_t maxIndex = resultStack.size() - 1;
            BasicOperation* operation = GetOperation(part);

            if (operation->GetType() == OperationType::Binary)
            {
                result = operation->Calculate({ std::stod(resultStack[maxIndex - 1]), std::stod(resultStack[maxIndex]) });
                resultStack.pop_back();
                resultStack.pop_back();
            }
            else
            {
                result = operation->Calculate({ std::stod(resultStack[maxIndex]) });
                resultStack.pop_back();
            }

            resultStack.push_back(std::to_string(result));
        }
    }

    return std::stod(resultStack.back());
}