#include "calculator.h"
#include "expression_tree.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

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
    //clean expression if previously undefined
    if (expression_.str() == "inf" || expression_.str() == "Undefined")
    {
        expression_.str("");
    }
    expression_ << symbol;
}


std::string Calculator::eval_expression()
{
    std::string res = "";
    std::cout << "Evaluating " << expression_.str() << std::endl;
    //Remove spaces from expression
    Calculator::clean_expression_();
    //Evaluate expression while checking for validity
    ExpressionTree evaluator = ExpressionTree(expression_.str());
    expression_.str(evaluator.get_expr());
    // evaluator.print();
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

void Calculator::set_expression(std::string expr)
{
    expression_.str(expr);
}
void Calculator::clean_expression_()
{
    std::string expr = expression_.str();
    //Matt Price: https://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c
    expr.erase(remove_if(expr.begin(), expr.end(), isspace), expr.end());
    std::cout << "Cleaned to " << expr << std::endl;
    expression_.str(expr);
}
