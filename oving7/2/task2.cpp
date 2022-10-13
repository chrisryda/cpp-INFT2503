#include "set.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main () 
{   
    Set empty_set1; 
    empty_set1.print();

    Set empty_set2;
    empty_set2.create_empty_set();
    empty_set2.print();

    Set set1({9, 2, 4, 13, 27});
    set1.print("set1: ");

    Set set2;
    vector<int> numbers = {3, 1, 14, 27, 29, 2};
    set2.create_set(numbers);
    set2.print("set2: ");

    Set union_set = Set::get_union_set(set1, set2);
    union_set.print("Union of set1 and set2: ");

    set1.add_number_to_set(99);
    set1.print("set1 after adding 99 to it: ");

    set1 = empty_set1;
    set1.print();
}
