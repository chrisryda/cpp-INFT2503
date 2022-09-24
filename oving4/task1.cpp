#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    vector<double> numbers = {1.5, 4.75, 11.3, 66.6, 29.9};

    cout << numbers.front() << endl;
    cout << numbers.back() << endl;

    numbers.emplace(numbers.begin() + 1, 2.33);
    cout << numbers.front() << endl;

    auto it = find(numbers.begin(), numbers.end(), 11.3);
    
    if (it != numbers.end()) 
    {
        std::cout << "Element found in vector: " << *it << '\n';
    }
    
    return 0;
}