#include <iostream>
#include <string>
#include <vector>
#include "main.h"
using namespace std;

std::vector<std::string> Explode(char seperator, const char* str)
{
    std::vector<std::string> result;
    // TODO: write code that "splits" the input string by the seperator
    int i = 0;
    string substring;
    while (str[i] != '\0')
    {
        if (str[i] != seperator)
        {
            substring.push_back(str[i]);
        }
        else
        {
            if (substring != "")
            {
                result.push_back(substring);
            }
            substring.clear();
        }

        i++;
    }
    if (substring != "")
    {
        result.push_back(substring);
    }
    
   
    // store each word in the resuts.

    return result;
}

int main(int argc, char* argv)
{
    std::cout << "---------------------------------------------------------" << std::endl;
    auto words = Explode(' ', "the quick brown fox jumps over the lazy dog");
    std::cout << "There are: " << words.size() << std::endl << std::endl;
    for (auto& w : words) {
        std::cout << w << std::endl;
    }
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << "---------------------------------------------------------" << std::endl;
    auto kvp = Explode('&', "aaa:10&bbb:20ccc:30&&&&&ddd:30");
    std::cout << "There are: " << kvp.size() << std::endl << std::endl;
    for (auto& w : kvp) {
        std::cout << w << std::endl;
    }
    std::cout << "---------------------------------------------------------" << std::endl;

    return 0;
}