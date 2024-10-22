#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "stock.hpp"

class Interpreter
{
    // Класс интерпретатора
    // Нужен для передачи команд из консоли в класс-контейнер
    private:
        Stock* src;
        bool running = 0;
        bool last = 1;

        int get_command();
        void prompt();
        void print_help();

        void add();
        void pop();

        void read_json();
        void write_json();

    public:
        Interpreter();
        ~Interpreter();

        void loop();
};

#endif