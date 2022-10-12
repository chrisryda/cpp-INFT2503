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
	Fraction fraction1(25, 5);
	Fraction fraction_result1;
	fraction_result1 = fraction1 - 3;
	print("25/5 - 3 = ", fraction_result1);

	Fraction fraction_result2;
	fraction_result2 = 3 - fraction1;
	print("3 - 25/5 = ", fraction_result2);

}
