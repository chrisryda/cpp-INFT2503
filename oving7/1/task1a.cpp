#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &fraction)
{
	cout << text << fraction.numerator << " / " << fraction.denominator << endl;
}

int main()
{
	Fraction fraction1(30, 5);
	Fraction result1 = fraction1 - 5;
	print("30/5 - 5 = ", result1);

	Fraction result2 = 5 - fraction1;
	print("5 - 30/5 = ", result2);
}
