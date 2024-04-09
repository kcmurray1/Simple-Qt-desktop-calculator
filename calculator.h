#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <sstream>
#include "expression_tree.h"

class Calculator
{
public:
    //Constructor and Destructor
    Calculator();
    ~Calculator();

    //Add symbols for calculations
    void add_symbol(std::string);
    std::string eval_expression();
    void clear();
    std::string get_expression();
    void set_expression(std::string);
    std::string last_calculation;

private:
    std::stringstream expression_;
    void clean_expression_();
};

#endif // CALCULATOR_H
