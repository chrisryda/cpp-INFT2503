#include <iostream>

using namespace std;

template <typename Type>
bool equals(Type a, Type b)
{   
    cout << "General version ";
    return a == b;
}

bool equals(double a, double b)
{
    cout << "Specialized version ";
    double treshold = 0.00001;
    return abs(a-b) < treshold;
}

int main()
{
    cout << equals(1, 2) << "\n";
    cout << equals("abc", "abc") << "\n";
    cout << equals(1.211114, 1.211113) << "\n";
}