#include <iostream>

int main()
{
    double number;
    double *pointer = &number;
    double &ref = number;

    number = 10;
    std::cout << number << "\n";
    
    *pointer = 11;
    std::cout << number << "\n";
    
    ref = 12;
    std::cout << number << "\n"; 
}