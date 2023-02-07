//Создать шаблонный класс для работы с строками.
//В классе перегрузить оператор (). 
//Память под строку выделять динамически, использовать конструктор с параметрами, конструктор копирования.
//В программе предусмотреть обработку исключительных ситуаций.

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class String
{
private:
    T *_st;
    int _len;
public:
    String (const T str[], int len)
    {
        _st = new T[len];
        _len = len;
        for (int i = 0; i < len; i++)
            _st[i] = str[i];
    }
    ~String()
    {
        delete[] _st;
    }
    String (String &obj)
    {
        _len = obj._len;
        _st = new T[_len];
        for (int i = 0; i < _len; i++)
            _st[i] = obj._st[i];
    }
    T* operator()(int begin, int end)
    {
        if (begin > end || begin < 0 || end < 0)
        {
            T *st = new T[1];
            st[0] = 0;
            return st;
        }
        if (end == begin)
        {
            T *st = new T[1];
            st[0] = this->_st[begin];
            return st;
        }

        T *tmp = new T[end - begin];
        int i = 0;
        do
        {
            tmp[i++] = this->_st[begin++];
        } while (begin != end);

        return tmp;
    }
};

int main()
{
    String<char> obj("qwertyuiop", 10);
    String<char> b = obj;
    char *str = b(1, 5);
    cout << str;
    return 0;
}
