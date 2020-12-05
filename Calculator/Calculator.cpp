#include "Calculator.h"

typedef BasicOperation* (*Loader) (); //defining the type of functions to read from the library

void Calculator::LoadLibraries() //loading operations from dll and message about input rules
{
    std::string dllDirectory = "./dll";

    std::cout << "Operations are available to you:" << std::endl;

    if (std::filesystem::exists(dllDirectory))
        for (auto dll : std::filesystem::directory_iterator(dllDirectory))
        {
            HMODULE library = LoadLibraryA(dll.path().string().c_str());
            libraries.push_back(library);

            Loader loader = (Loader)GetProcAddress(library, "Load");
            if (GetLastError() != 0)
                return;

            BasicOperation* operation = loader();
            std::cout << operation->GetName() << "; ";
            operations.push_back(operation);
        }

    std::cout << "\nSeparate each structure with a space, please!\n" << std::endl;
}

void Calculator::Processing() //reading an expression and counting it using the reverse polish notation algorithm
{
    std::cout << "Input your expression:" << std::endl;
    std::getline(std::cin, expression);
    std::cout << std::endl;

    Split();
    if (!IsCorrect())
    {
        std::cout << "Syntax error" << std::endl;
        return;
    }

    PolishNotation();
    if (notation.empty())
        return;

    std::cout << "Result: " << StackMachine() << std::endl;
}

Calculator::~Calculator() //destructor that unloads libraries
{
    for (HMODULE library : libraries)
        FreeLibrary(library);
}