#include <iostream>
#include "interpreter.hpp"

using namespace std;

int main()
{
    Interpreter inter = Interpreter();

    inter.loop();
    
    return 0;
}