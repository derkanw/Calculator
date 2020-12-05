#pragma once
#include <deque>
#include <iostream>
#include <filesystem>
#include <windows.h>
#include <vector>
#include <string>
#include "BasicOperation.h"

class Calculator //calculator class working with dll
{
private:
    std::vector<HMODULE> libraries; //contains all linked libraries
    std::vector<BasicOperation*> operations; //contains all used operations from dll
    std::string expression; //stores the calculated expression received from the console
    std::vector<std::string> parts; //logical units of expression
    std::deque<std::string> stack; //stores part of the operations in the reverse polish notation algorithm
    std::vector<std::string> notation; //expression after applying the reverse polish notation algorithm
    std::deque<std::string> resultStack; //stored numbers to calculate the result

    void Split(void); //dividing the input string into logical units
    void PolishNotation(void); //converting the input string according to the reverse polish notation algorithm
    double StackMachine(void); //calculating the result of the entered expression in the reverse polish notation algorithm

    bool DigitOrPostfix(std::string part); //numbers and postfix operations are added directly to the reverse polish notation
    bool LBracketOrPrefix(std::string part); //left brackets and prefix operations are added immediately to the stack entry
    bool RBracket(std::string part); //when a right bracket appears, all stack elements up to the left bracket are unloaded
    bool Binary(std::string part); //binary operations are written according to the priority of the operations
    void PushRemainder(void); //writing the remaining elements of the stack to the reverse polish notation

    bool IsDigit(std::string part); //checking that the logical unit of the expression is an integer or decimal number
    bool IsCorrect(void); //checking that the given line has the same number of '(' and ')'
    bool IsCorrectType(std::string part, OperationType type); //checking if the type of the operation matches the given type
    bool IsHigherPriority(std::string part1, std::string part2); //checking that the first operation has a higher priority
    bool HasOpeningBracket(void); //checking the correct position of the brackets

    BasicOperation* GetOperation(std::string part); //returns the corresponding operation by the given value

public:
    Calculator() = default;

    void LoadLibraries(); //loading operations from dll and message about input rules
    void Processing(); //reading an expression and counting it using the reverse polish notation algorithm

    ~Calculator(); //destructor that unloads libraries
};