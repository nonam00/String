//работает только на версии 2014 года

#include <iostream>
#include <Windows.h>

class String
{

public:

    String(const char* _str)
    {
        size = (int)strlen(_str);
        str = new char[size+1];
        strcpy_s(str, size + 1, _str);
    }

    String(const String& obj) : size{obj.size}
    {
        str = new char[size + 1];
        strcpy_s(str, size + 1, obj.str);
    }

    ~String()
    {
        delete[]str;
    }

    String& operator=(const String& obj)
    {
        size = obj.size;
        delete[]str;
        str = new char[size + 1];
        strcpy_s(str, size + 1, obj.str);
        return*this;
    }

    friend String operator+(const String& obj1, const String& obj2)
    {
        int new_size = obj1.size + obj2.size;
        char* new_str = new char[new_size + 1];
        strcpy_s(new_str, new_size, obj1.str);
        strcat_s(new_str, new_size+1, obj2.str);
        return String(new_str);
    }

    String& operator+=(const String& obj)
    {
        size += obj.size;
        char* new_str = new char[size + 1];
        strcpy_s(new_str, size, str);
        delete[]str;
        str = new char[size + 1];
        strcpy_s(str, size, new_str);
        strcat_s(str, size + 1, obj.str);
        return*this;
    }

    friend bool operator==(const String& obj1, const String& obj2)
    {
        if (strcmp(obj1.str, obj2.str) == 0)
            return true;
        else
            return false;
    }
    friend bool operator!=(const String& obj1, const String& obj2)
    {
        if (strcmp(obj1.str, obj2.str) == 0)
            return false;
        else
            return true;
    }
    friend bool operator>(const String& obj1, const String& obj2)
    {
        if (obj1.size > obj2.size)
            return true;
        else
            return false;
    }
    friend bool operator>=(const String& obj1, const String& obj2)
    {
        if (obj1.size >= obj2.size)
            return true;
        else
            return false;
    }

    friend bool operator<(const String& obj1, const String& obj2)
    {
        if (obj1.size < obj2.size)
            return true;
        else
            return false;
    }
    friend bool operator<=(const String& obj1, const String& obj2)
    {
        if (obj1.size <= obj2.size)
            return true;
        else
            return false;
    }

    const char& operator[](int) const; //не пон€л

    char& operator[](int index)
    {
        return str[index];
    }

    friend std::ostream& operator<<(std::ostream& out, const String& obj)
    {
        out << obj.str << " " << obj.size << std::endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, String& obj)
    {
        in >> obj.size;
        delete[]obj.str;
        obj.str = new char[obj.size+1];
        in >> obj.str;
        return in;
    }

private:

    char* str;
    int size;

};




int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    String string_test("text");

    String string_test2(string_test); //инициализаци€ при помощи другого объекта String

    String string_test3("string"); // приравнивание строки
    string_test3 = string_test2;
    std::cout << string_test3; //вывод при помощи ostream

    String string_test4("a"); //сложение 2х строк
    string_test4 = string_test + string_test3;
    std::cout << string_test4;

    String string_test5("str"); //прибавление к строке
    string_test5 += string_test;
    std::cout << string_test5;

    //проверка логических функций
    std::cout << (string_test == string_test) << std::endl; 
    std::cout << (string_test != string_test5) << std::endl;
    std::cout << (string_test > string_test5) << std::endl;
    std::cout << (string_test < string_test5) << std::endl;
    std::cout << (string_test >= string_test) << std::endl;
    std::cout << (string_test <= string_test) << std::endl;

    String string_test6("qwer");
    std::cout << string_test6[3] << std::endl; //проверка образени€ по индексу

    String string_test7("a");
    std::cout << "¬ведите размер и текст" << std::endl;
    std::cin >> string_test7; //ввод через istream
    std::cout << string_test7 << std::endl;

	return 0;
}