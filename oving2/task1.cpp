#include <iostream>

int i = 3;
int *p = &i;
int j = 5;
int *q = &j;

int main() 
{
    std::cout << i << " is the value of i" << std::endl;
    std::cout << *p << " is the value of *p" << std::endl;

    std::cout << &i << " is the address of i" << std::endl;
    std::cout << p << " is the address of *p\n" << std::endl;

    std::cout << j << " is the value of j" << std::endl;
    std::cout << *q << " is the value of *q" << std::endl;

    std::cout << &j << " is the address of j" << std::endl;
    std::cout << q << " is the address of q\n" << std::endl;

    // Task 1b
    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;
    std::cout << *p << " " << *q << std::endl;
}
