#include <iostream>
#include <cstdlib>
#include <fstream>

void read_temperatures(double temperatures[], int length);

int main() {

    int length = 20;
    double temperatures[length];
    int lower = 0, mid = 0, upper = 0;
    int temp;

    read_temperatures(temperatures, length);

    for (size_t i = 0; i < length; i++)
    {
        temp = temperatures[i];

        if (temp < 10)
        {
            lower++;
        } 
        else if ( temp > 20)
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

void read_temperatures(double temperatures[], int length) {
        const char filename[] = "./temperatures.txt";
        std::ifstream file;
        file.open(filename);

        if (!file) {
            std::cout << "Error opening file." << std::endl;
            exit(EXIT_FAILURE);
        }

        int i = 0;
        int number;
        while (file >> number) {
                temperatures[i] = number;
                i++;
        }

        file.close();
    }