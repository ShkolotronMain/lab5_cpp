#include "interpreter.hpp"

int main()
{
    Interpreter* inter = new Interpreter();

    inter->loop();

    delete inter;

    return 0;
}