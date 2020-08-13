#include <iostream>
int GenerateFib(int num)
{
    int n, t1 = 0, t2 = 1, nextTerm = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            std::cout << " " << t1;
            continue;
        }
        if (i == 2)
        {
            std::cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
   }
    return 0;
}
int main(int argc, char** argv)
{
    std::cout << GenerateFib(13) << std::endl; //10 = 2 + 8
    std::cout << GenerateFib(17) << std::endl; //10 = 2 + 8
    std::cout << GenerateFib(45) << std::endl; //44 = 2 + 8 + 34
    std::cout << GenerateFib(55) << std::endl; //44 = 2 + 8 + 34
}