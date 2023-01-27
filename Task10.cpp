//Создать класс для работы со строками.
//В классе перегрузить оператор + для сложения строк. 
//Память под строку выделять динамически, использовать конструктор с параметрами, конструктор копирования.
//В программе предусмотреть обработку исключительных ситуаций.

#include <iostream>

class String
{
    char *str;
public:
    explicit String(const char *str2)
    {
        try
        {
            str = new char[strlen(str2) + 1];
        }
        catch (std::bad_alloc)
        {
            std::cout << "bad allocation" << std::endl;
        }
        for (int i = 0; i < strlen(str2); i++)
            str[i] = str2[i];
        str[strlen(str2) + 1] = '\0';
    }
    String (String &str2)
    {
        try
        {
            str = new char[strlen(str2.str) + 1];
        }
        catch (std::bad_alloc)
        {
            std::cout << "bad allocation" << std::endl;
        }
        for (int i = 0; i < strlen(str2.str); i++)
            str[i] = str2.str[i];
        str[strlen(str2.str) + 1] = '\0';
    }
    ~String()
    {
        delete [] str;
    }
    String operator+ (String str2)
    {
        char *tmp;
        int size = strlen(this->str) + strlen(str2.str) + 1;
        try
        {
            tmp = new char[size];
        }
        catch (std::bad_alloc)
        {
            std::cout << "Bad allocation" << std::endl;
        }
        strcpy(tmp, this->str);
        int j = 0;
        for (int i = strlen(this->str); i < size; i++)
        {
            tmp[i] = str2.str[j];
            j++;
        }
        tmp[size] = '\0';
        return String(tmp);
    }
    void Show()
    {
        std::cout << str << std::endl;
    }
};

int main()
{
    String str1("hello");
    String str2("world");
    str1.Show();
    str2.Show();
    String str3 = str1 + str2;
    str3.Show();
}
