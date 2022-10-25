#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

int main()
{
	vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
	vector<int> v2 = {2, 3, 12, 14, 24};

	// Task a
	vector<int>::iterator it = find_if(v1.begin(), v2.end(), [](const int &num) { 
		return num > 15; 
	});
	cout << "The first element larger than 15 is : " << *it << endl;

	// Task b
	bool equal = std::equal(v1.begin(), v1.begin() + 5, v2.begin(), [](const int &a, const int &b) { 
		return abs(a-b) <= 2; 
	});
	if (equal) {
		std::cout << "The contents of the first 5 elements of both sequences are equal.\n";
	}

	equal = std::equal(v1.begin(), v1.begin() + 4, v2.begin(), [](const int &a, const int &b) { 
		return abs(a-b) <= 2; 
	});
	if (equal) {
		std::cout << "The contents of the first 4 elements of both sequences are equal.\n";
	}

	// Task c
	replace_copy_if (v1.begin(), v1.end(), v1.begin(), [](const int num) {
		return num%2 != 0;
	}, 100);
	cout << v1 << endl;

}
