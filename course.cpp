#include <iostream>
#include "course.hpp"

Course::Course()
{

}

Course::Course(json val)
{
    currency = val["currency"];
    state = val["state"];
    code = val["code"];
    subunit = val["subunit"];
    fraction = val["fraction"];
    rate = val["rate"];
}

Course::~Course()
{

}

void Course::print()
{
    
}

void Course::read_from_console()
{
    string trash;

    getline(cin, trash);
    cout << "Введите название валюты:" << endl;
    getline(cin, currency);
    cout << "Введите государство:" << endl;
    getline(cin, state);
    cout << "Введите код валюты:" << endl;
    getline(cin, code);
    cout << "Введите название разменной валюты:" << endl;
    getline(cin, subunit);
    cout << "Сколько разменной валюты в основной:" << endl;
    cin >> fraction;
    cout << "Введите курс валюты к российскому рублю:" << endl;
    cin >> rate;
    getline(cin, trash);   
}

json Course::get_object()
{
    json value;
    value["currency"] = currency;
    value["state"] = state;
    value["code"] = code;
    value["subunit"] = subunit;
    value["fraction"] = fraction;
    value["rate"] = rate;
    return value;
}

string Course::get_code()
{
    return code;
}

double Course::get_rate()
{
    return rate;
}

bool operator==(Course c1, Course c2)
{
    bool res = 0;

    if (c1.get_object() == c2.get_object())
        res = 1;
    else
        res = 0; 

    return res;
}

ostream& operator<<(ostream& out, const Course& cl)
{
    out << "===================" << endl;
    out.setf(ios::fixed);
    out.precision(2);
    out << cl.currency << endl;
    out << cl.state << endl;
    out << cl.code << endl;
    out << "1 " + cl.code + " = " << cl.rate << endl;
    out << "===================" << endl;

    return out;
}
