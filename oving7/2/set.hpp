#pragma once

#include <string>
#include <vector>

class Set
{
public:
    std::vector<int> set;

    Set();
    Set(std::vector<int> set);
    Set(const Set &) = default;

    void print(const std::string &text) const;
    std::vector<int> get_set() const;
    void create_set(std::vector<int> set_);
    void create_empty_set();
    void add_number_to_set(const int num); 
    static Set get_union_set(Set &set, Set &other_set);
    Set &operator=(Set &other_set);
};