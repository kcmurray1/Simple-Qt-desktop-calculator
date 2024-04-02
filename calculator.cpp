#include "calculator.h"
#include <iostream>
#include <sstream>
#include <string>
//Constructor
Calculator::Calculator()
{
    std::cout << "Creating Calculator!" << std::endl;
}

//Destructor
Calculator::~Calculator()
{
    std::cout << "Destroying Calculator!" << std::endl;
}

//Add digit to expression_
void Calculator::addSymbol(std::string symbol)
{
    expression_ << symbol;
}

std::string Calculator::evalExpression()
{
    std::string res = "";
    std::cout << "Evaluating " << expression_.str() << std::endl;
    //Validate expression
    //Return "Syntax Error"
    //Otherwise evaluate
    return res;
}

void Calculator::clear()
{
    std::cout << "Clearing..." << std::endl;
    expression_.str("");
}

std::string Calculator::getExpression()
{
    return expression_.str();
}

