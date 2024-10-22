#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include "course.hpp"

// Класс-контейнер
class Stock
{
    private:
        // Массив с курсами валют
        Course* mas;
        // Количество элементов на рынке
        int cnt;

        // Разница двух элементов на рынке
        double diff(Course, Course);

    public:
        Stock();
        ~Stock();
        
        bool pop(int);

        bool read_from_json(string);  // TODO: переписать на оператор
        bool write_to_json(string);   // TODO: переписать на оператор

        void print_all();
        bool print_exp();

        // Добавление элемента на рынок
        void operator+=(Course);
};

#endif