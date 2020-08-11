#include <iostream>

void print_pyramid(int height) 
{
    // num of spaces
    int k = 2 * height - 2;

    if (height == 0)
        return;

    else if (height > 0)
    {
        // making standing pyramid
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < k; i++)
            {
                for (int j = 0; j < k; j++)
                    std::cout << " ";

                //Decrementing k after each loop
                k = k - 1;

                for (int j = 0; j <= i; j++)
                {
                    std::cout << "* ";
                }

                std::cout << std::endl;
            }
        }
    }
}



int main(int argc, char** argv)
{
    std::cout << "=======================================" << std::endl;
    print_pyramid(6);
    std::cout << "=======================================" << std::endl;
    print_pyramid(7);
    std::cout << "=======================================" << std::endl;
    print_pyramid(-1);
    std::cout << "=======================================" << std::endl;
    print_pyramid(-6);

    return 0;
}