#include <string>
#include <iostream>
int matchClosingBracket(const std::string& str, int loc)
{
    // return the index of the closing bracket
    // if no closing bracket is found, return -1
    // if the character at str[loc] is not an opening bracket, return -1.

    return -1;
}

int main(int argc, char** argv)
{
    std::string bf = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

    std::cout << matchClosingBracket(bf, 1) << std::endl; // -1
    std::cout << matchClosingBracket(bf, 8) << std::endl; // 48
    std::cout << matchClosingBracket(bf, 14) << std::endl; // 33
    std::cout << matchClosingBracket(bf, 43) << std::endl; // 45
    std::cout << matchClosingBracket(bf, 101) << std::endl; // -1
    std::cout << matchClosingBracket(bf, -1) << std::endl; // -1

}