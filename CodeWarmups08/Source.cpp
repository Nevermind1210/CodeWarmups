#include <iostream>
#include <vector>

int findOdd(std::vector<int> arr) 
{
    int result = 0;
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        result = result ^ arr[i];
    }
    return result;
}
int main()
{
    int result1;
    int result2;
    int result3;
    

    result1 = findOdd({ 1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5 }); //return -1
    result2 = findOdd({ 20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5 }); // return 5
    result3 = findOdd({ 10 }); // return 10

    std::cout << result1 << std::endl
        << result2 << std::endl
        << result3 << std::endl;
}