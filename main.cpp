#include <iostream>
#include "stock.hpp"
#include "course.hpp"

using namespace std;

//TODO: переписать более эффективно
int main()
{
    Stock obj = Stock();

    bool running = 1;
    while (running)
    {
        cout << "[LAB]> ";
        string command;
        cin >> command;
        cout << endl;

        if (command == "add")
        {
            Course nc = Course();
            nc.read_from_console();
            obj.add(nc);
            cout << endl;
        }
        else if (command == "pop")
        {
            int c;
            cout << "Введите индекс удаляемого элемента: ";
            cin >> c;
            
            obj.pop(c);
        }
        else if (command == "read_from_json")
        {
            string path;
            cout << "Введите путь к файлу" << endl;
            cin >> path;

            obj.read_from_json(path);

            cout << endl;
        }
        else if (command == "write_to_json")
        {
            string path;
            cout << "Введите путь к файлу" << endl;
            cin >> path;

            obj.write_to_json(path);

            cout << endl;
        }
        else if (command == "print_all")
        {
            obj.print_all();
            cout << endl;
        }
        else if (command == "print_exp")
        {
            obj.print_exp();
            cout << endl;
        }
        else if (command == "help")
        {
            cout << "Список доступных комманд: " << endl;
            cout << "add - добавить в контейнер" << endl;
            cout << "pop - убрать из контейнера" << endl;
            cout << "read_from_json - ввести несколько из JSON (перезапись)" << endl;
            cout << "write_to_json - сохранить всё в JSON" << endl;
            cout << "print_all - вывести все" << endl;
            cout << "get_cnt - получить количество" << endl;
            cout << "help - список команд" << endl;
            cout << "exit - выход" << endl << endl; 
        }
        else if (command == "exit")
        {
            cout << "Выход" << endl;
            running = 0;
        }
        else
        {
            cout << "Неверная комманда" << endl;
            cout << "Для получения списка комманд введите help" << endl;
        }
    }

    return 0;
}