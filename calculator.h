#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <sstream>
class Calculator
{
public:
    //Constructor and Destructor
    Calculator();
    ~Calculator();

    //Add symbols for calculations
    void addSymbol(std::string);
    std::string evalExpression();
    void clear();
    std::string getExpression();
private:
    std::stringstream expression_;
};

#endif // CALCULATOR_H
