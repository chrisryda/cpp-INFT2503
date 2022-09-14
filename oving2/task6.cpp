#include <iostream>

int find_sum(const int *table, int length) 
{
    int sum = 0;
    for (int i = 0; i < length; i++) 
    {
        sum += table[i];
    }

    return sum;
}

int main() 
{   
    const int length = 20;
    int table[length];
    int *pointer = table;
    for (int i = 0; i < length; i++)
    {
        table[i] = (i + 1); 
    }

    std::cout << "Sum of first ten numbers in table: " << find_sum(pointer, 10) << "\n";
    pointer += 10;

    std::cout << "Sum of next five numbers in table: " << find_sum(pointer, 5) << "\n";
    pointer += 5;

    std::cout << "Sum of last five numbers in table: " << find_sum(pointer, 5) << "\n";
}
