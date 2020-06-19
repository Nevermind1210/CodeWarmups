#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;


double RPN(const string &expr)
{
    std::istringstream iss(expr);
    std::vector<double> stack;
    std::cout << "Input\tOperation\tStack after" << std::endl;
    std::string token;
    while (iss >> token) {
        std::cout << token << "\t";
        double tokenNum;
        if (std::istringstream(token) >> tokenNum) {
            std::cout << "Push\t\t";
            stack.push_back(tokenNum);
        }
        else {
            std::cout << "Operate\t\t";
            double secondOperand = stack.back();
            stack.pop_back();
            double firstOperand = stack.back();
            stack.pop_back();
            if (token == "*")
                stack.push_back(firstOperand * secondOperand);
            else if (token == "/")
                stack.push_back(firstOperand / secondOperand);
            else if (token == "-")
                stack.push_back(firstOperand - secondOperand);
            else if (token == "+")
                stack.push_back(firstOperand + secondOperand);
            else if (token == "^")
                stack.push_back(std::pow(firstOperand, secondOperand));
            else { //just in case
                std::cerr << "Error" << std::endl;
                std::exit(1);
            }
        }
        std::copy(stack.begin(), stack.end(), std::ostream_iterator<double>(std::cout, " "));
        std::cout << std::endl;
    }
    return stack.back();
}
int main(int argc, char** argv)
{
    {
        std::string equasion = "10 20 +";
        std::cout << equasion << " = " << RPN(equasion) << "\t\t\tExpected: 30" << std::endl;
    }
    {
        std::string equasion = "10 20 30 + *";
        std::cout << equasion << " = " << RPN(equasion) << "\t\t\tExpected: 500" << std::endl;
    }
    {
        std::string equasion = "20 10 / 4 *";
        std::cout << equasion << " = " << RPN(equasion) << "\t\t\tExpected: 8" << std::endl;
    }
    {
        std::string equasion = "20 10 - 15 +";
        std::cout << equasion << " = " << RPN(equasion) << "\t\t\tExpected: 25" << std::endl;
    }

    return 0;
}


// STEPS:
    // - explode the equasion by space ' ' and store in variable called 'tokens'
    // - loop through each token... if its a number push its integer value onto the 'stack'
    //      HINT: use std::stoi to convert string to an int
    //      HINT: create an std::vector<int> to represent the 'stack'
    // - if the token is a symbol ('+', '-', '/', '*') pop the last 2 values off the stack,
    //   do math on them ( one of the + - / * ), and push the result back onto the stack.
    //
    // - once you've iterated over all tokens, the final result of the equasion will be the first and only
    //   item left in the stack.
    //
    // NOTE: at the end, if the stack has more than 1 value, the equasion was not correctly formed.
    //       dont worry about error handeling for now...
    // 