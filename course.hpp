#ifndef COURSE_H
#define COURSE_H

#include <fstream>
#include "libraries/json.hpp"

using namespace std;
using namespace nlohmann;

class Course
{
    // Класс курс
    // Основной класс
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

        friend ostream& operator<<(ostream&, const Course&);

        friend bool operator==(Course, Course);
};

#endif