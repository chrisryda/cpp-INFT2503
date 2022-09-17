#pragma once 
#include <string>

using namespace std;

const double sales_tax = 1.25;

class Commodity {
public:
    Commodity(const string &name_, const int id_, double price_);

    const string &get_name() { return name; }
    const int get_id() { return id; }
    double get_price() { return price; }
    double get_price(double units) { return price * units; }
    double get_price_with_sales_tax() { return price * sales_tax; }
    double get_price_with_sales_tax(double units) { return (price * sales_tax) * units; }

    void set_price(double price) { Commodity::price = price; }


private:
    string name;
    int id;
    double price;
};

Commodity::Commodity(const string &name_, const int id_, double price_) : name(name_), id(id_), price(price_) {}