#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <fstream>
#include "course.hpp"

class Stock
{
    private:
        Course* mas;
        int cnt;

        double diff(Course, Course);

    public:
        Stock();
        ~Stock();

        void add(Course);
        void pop(int);

        void read_from_json(string);
        void write_to_json(string);

        void print_all();
        void print_exp();
};

#endif