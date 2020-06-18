#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isIsogram(string str)
{
    // TODO: write your code here
    sort(str.begin(), str.end());

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == str[i + 1]) {
            return false;
        }
    }

    // return true only if all characters in the word are unique, (ignore case) otherwise return false.
    return true;
}

int main(int argc, char** argv)
{
    std::cout << "Aaron" << "\t" << isIsogram("Aaron") << std::endl;

    // random words from a random word generator :P
    std::cout << "Bake" << "\t" << isIsogram("Bake") << std::endl;
    std::cout << "Lay" << "\t" << isIsogram("Lay") << std::endl;
    std::cout << "Issue" << "\t" << isIsogram("Issue") << std::endl;
    std::cout << "Wood" << "\t" << isIsogram("Wood") << std::endl;
    std::cout << "Swop" << "\t" << isIsogram("Swop") << std::endl;
    std::cout << "Coup" << "\t" << isIsogram("Coup") << std::endl;
    std::cout << "Trouser" << "\t" << isIsogram("Trouser") << std::endl;
    std::cout << "Superior" << "\t" << isIsogram("Superior") << std::endl;
    std::cout << "History" << "\t" << isIsogram("History") << std::endl;
    std::cout << "Disclose" << "\t" << isIsogram("Disclose") << std::endl;

    return 0;
}

