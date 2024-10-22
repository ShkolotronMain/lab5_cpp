#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include "course.hpp"

class Stock
{
    // Класс рынок
    // Класс-контейнер
    private:
        Course* mas;
        int cnt;

        double diff(Course, Course);

    public:
        Stock();
        ~Stock();

        void add(Course);
        bool pop(int);

        bool read_from_json(string);
        bool write_to_json(string);

        void print_all();
        bool print_exp();
};

#endif