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
void Calculator::add_symbol(std::string symbol)
{
    expression_ << symbol;
}


std::string Calculator::eval_expression()
{
    std::string res = "";
    std::cout << "Evaluating " << expression_.str() << std::endl;

    //Evaluate expression while checking for validity
    return res;
}

void Calculator::clear()
{
    std::cout << "Clearing..." << std::endl;
    expression_.str("");
}

std::string Calculator::get_expression()
{
    return expression_.str();
}

void Calculator::clean_expression_()
{
    return;
}
