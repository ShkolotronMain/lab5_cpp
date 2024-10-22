#include <iostream>
#include "course.hpp"
#include "libraries/json.hpp"

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
    currency = "";
    state = "";
    code = "";
    subunit = "";
    fraction = 0;
    rate = 0;
}

void Course::print()
{
    cout << "===================" << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << currency << endl;
    cout << state << endl;
    cout << code << endl;
    cout << "1 " + code + " = " << rate << endl;
    cout << "===================" << endl;
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
