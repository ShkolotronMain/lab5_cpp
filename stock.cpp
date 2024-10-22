#include "stock.hpp"

using namespace nlohmann;

// Конструктор
Stock::Stock()
{
    cnt = 0;
    mas = new Course[0];
}

// Деструктор
Stock::~Stock()
{
    delete[] mas;
    cnt = 0;
}

void Stock::add(Course _course)
{
    cnt++;
    Course* new_mas = new Course[cnt];
    for (int i=0; i<cnt-1; i++)
        new_mas[i] = mas[i];
    Course* old_mas = mas;
    mas = new_mas;
    delete[] old_mas;

    mas[cnt-1] = _course;
}

bool Stock::pop(int index)
{
    if (index>=0 && index < cnt)
    {
        int old_cnt = cnt;
        cnt--;
        Course* new_mas = new Course[cnt];
        
        for (int i=0, j=0; i<old_cnt; i++)
            if (i != index)
            {
                new_mas[j] = mas[i];
                j++;
            }

        Course* old_mas = mas;
        mas = new_mas;
        delete[] old_mas;

        cout << "Элемент удалён" << endl;
        return 1;
    }
    else
    {
        cerr << "Элемент с заданным индексом не существует" << endl;
        return 0;
    }
}

void Stock::print_all()
{
    for (int i=0; i<cnt; i++)
        cout << mas[i];
}

double Stock::diff(Course left, Course right)
{
    return (left.get_rate() - right.get_rate());
}

bool Stock::print_exp()
{
    Course usd = {};
    bool usd_exists = 0;

    cout << "Стоят дороже доллара:" << endl;

    for (int i=0; i<cnt && usd_exists==0; i++)
        if (mas[i].get_code().compare("USD") == 0)
        {
            usd = mas[i];
            usd_exists = 1;
        }

    if (usd_exists==1)
    {
        for (int i=0; i<cnt; i++)
            if (diff(usd, mas[i]) < 0)
            {
                mas[i].print();
                cout << endl;
            }
        return 1;
    }
    else
    {
        cerr << "\nДоллара в выборке нет, сравнение невозможно" << endl;
        return 0;
    }
        
}

bool Stock::read_from_json(string path)
{
    json file;

    ifstream in(path);
    if (in.is_open())
    {
        in >> file;
        cout << "Файл прочитан" << endl;
        in.close();

        for (int i=0; i<file["count"]; i++)
        {
            json value = file["values"][i];
            Course nc = Course(value);
            add(nc);
        }
        
        return 1;
    }
    else
    {
        cerr << "Ошибка открытия файла" << endl;
        return 0;
    }
}

bool Stock::write_to_json(string path)
{
    json file;

    file["count"] = cnt;

    for (int i=0; i<cnt; i++)
    {
        json value = mas[i].get_object();
        file["values"].push_back(value);
    }

    ofstream out(path);
    if (out.is_open())
    {
        out << file.dump(4);
        cout << "Файл записан" << endl;
        return 1;
    }
    else
    {
        cerr << "Ошибка открытия файла" << endl;
        return 0;
    }
}