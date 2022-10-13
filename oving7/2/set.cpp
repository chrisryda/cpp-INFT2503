#include "set.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Set::Set() : set(0) {}

Set::Set(vector<int> set)
{
	create_set(set);
}

void Set::print() const 
{
    if(!set.empty()) 
    {
        size_t size = set.size();
        cout << "{";
        for (size_t i = 0; i < size - 1; i++) {
            cout << set[i] << ", ";
        }
        cout << set[size-1] << "}" << endl;
    }
    else 
    {
        cout << "{}" << endl;
    }
}

void Set::print(const string &text) const 
{
    if(!set.empty()) 
    {
        size_t size = set.size();
        cout << text << "{";
        for (size_t i = 0; i < size - 1; i++) {
            cout << set[i] << ", ";
        }
        cout << set[size-1] << "}" << endl;
    }
    else 
    {
        cout << text << "{}" << endl;
    }
}

vector<int> Set::get_set() const
{
    return set;
}

void Set::create_set(vector<int> set_)
{
	set = set_;
}

void Set::create_empty_set() 
{
    set = vector<int>();
}

void Set::add_number_to_set(const int num)
{
    bool set_contains_element = find(set.begin(), set.end(), num) != set.end();
    if (!set_contains_element)
    {
        set.push_back(num);
    }
}

Set Set::get_union_set(Set &set, Set &other_set) 
{
    vector<int> union_set = vector<int>();

    Set largest_set;
    size_t largest_set_size = max(set.set.size(),other_set.set.size());
    if (largest_set_size == set.set.size())
    {
        largest_set.create_set(set.set);
    }
    else {
        largest_set.create_set(other_set.set);
    }

    for (size_t i = 0; i < largest_set_size; i++) 
    {
        int element = largest_set.set[i];

        bool union_set_contains_element = find(union_set.begin(), union_set.end(), element) != union_set.end();
        bool set_contains_element = find(set.set.begin(), set.set.end(), element) != set.set.end();
        bool other_set_contains_element = find(other_set.set.begin(), other_set.set.end(), element) != other_set.set.end();

        if (!union_set_contains_element)
        {
            if (set_contains_element && other_set_contains_element)
            {
                union_set.push_back(element);
            }
        }
    }

    return Set(union_set);
}

Set &Set::operator=(Set &other_set)
{
    set = other_set.get_set();
    return *this;
}
