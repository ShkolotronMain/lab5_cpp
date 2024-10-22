#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <fstream>
#include "libraries/json.hpp"

using namespace std;
using namespace nlohmann;

class Course
{
    private:
        string currency;
        string state;
        string code;
        string subunit;
        int fraction;
        double rate;

    public:
        Course();
        Course(json);
        ~Course();

        void read_from_console();

        void print();

        json get_object();
        string get_code();
        double get_rate();
};

#endif