#include <iostream>

int main()
{

    double temp;
    int lower = 0, mid = 0, upper = 0;

    std::cout << "Please enter 5 temperatures.\n";

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "Temperature number " + std::to_string(i + 1) + ": ";
        std::cin >> temp;

        if (temp < 10)
        {
            lower++;
        }
        else if (temp > 20)
        {
            upper++;
        }
        else
        {
            mid++;
        }
    }

    std::cout << "The number of temperatures below 10 is " + std::to_string(lower) + "\n";
    std::cout << "The number of temperatures between 10 and 20 is " + std::to_string(mid) + "\n";
    std::cout << "The number of temperatures above 20 is " + std::to_string(upper) + "\n";
}