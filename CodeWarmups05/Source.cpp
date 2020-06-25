#include <iostream>
#include <vector>
#include <array>
using namespace std;
int MaxDifference(const std::vector<int>& numbers)
{
    // find the smallest and largest number, and return the difference between them.
    // How many different ways can you achieve this?
    // - using loops? for loop?, range based for?, using iterator instead of random access? other?
    // - using recursion?
    // - making use of existing methods in the standard template library?
    // - what is the preformance of of your solution?
    // - - can you write it another way for faster execution time?
    int min = numbers[0];
    int max = min;
    for (auto i : numbers)
    {
        min = i < min ? i : min;
        max = i > max ? i : max;
    }

    return max - min;

}
int MaxDifference2(const std::vector<int>& numbers)
{
    // OPTIONAL CHALLENGE:
    // find the smallest and largest number, and return the difference between them.
    // Constraint: the selected largest number must appear AFTER the selected smallest number.
    // Constraint: the selected smallest number must appear BEFORE the selected largest number.
    // Note: with these constraints, there may be sqeuences that where a min and max cannot be calculated
    // How many different ways can you achieve this?
    // - using loops? for loop?, range based for?, using iterator instead of random access? other?
    // - using recursion?
    // - making use of existing methods in the standard template library?
    // - what is the preformance of of your solution?
    int diff = 0;

    for (int i = 1; i < numbers.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (diff < (numbers[i] - numbers[j]))
                diff = numbers[i] - numbers[j];
        }
    }

    return diff;
    return 0;
}
int main(int argc, char** argv)
{
    std::cout << MaxDifference({ 10, 15, 12, 8, 7, 31, 8 }) << std::endl; // 31 - 7 = 24
    std::cout << MaxDifference({ 12, 0, 4, 9, 2, 5, 8, 3 }) << std::endl; // 12 - 0 = 12
    std::cout << MaxDifference2({ 10, 15, 12, 8, 7, 31, 2 }) << std::endl; // 32 - 7 = 24 
    std::cout << MaxDifference2({ 12, 0, 4, 9, 2, 5, 8, 3 }) << std::endl; // 9 - 0 = 9 
    std::cout << MaxDifference2({ 12, 13, 14, 5, 6, 7, 8 }) << std::endl; // 8 - 5 = 3
    std::cout << MaxDifference2({ 12, 13, 14, 8, 7, 6, 5 }) << std::endl; // ?? cannot select min or max?
    std::cout << MaxDifference2({ 1, 2, 3, 4, 5, 6, 7, 8 }) << std::endl; // ?? cannot select a min or max?
    return 0;
}