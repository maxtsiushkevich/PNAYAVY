//Создать шаблонный класс для работы с одномерным массивом. 
//Перегрузить оператор для | для объединения массивов. 
//Память под массив выделять динамически, использовать конструктор с параметрами, конструктор копирования. 
//В программе предусмотреть обработку исключительных ситуаций.

#include <iostream>

template <typename T>
class Massiv
{
    T *mas;
    int size;
public:
    explicit Massiv(int size)
    {
        this->size = size;
        try
        {
            mas = new T[size];
        }
        catch(std::bad_alloc &bad)
        {
            std::cout << "bad allocation" << std::endl;
        }
    }
    Massiv(Massiv &a)
    {
        this->size = a.size;
        try
        {
            mas = new T[a.size];
        }
        catch(std::bad_alloc &bad)
        {
            std::cout << "bad allocation" << std::endl;
        }
        for(int i = 0; i < a.size; i++)
            mas[i] = a.mas[i];
    }
    ~Massiv()
    {
        delete [] mas;
    }
    Massiv operator | (Massiv &a)
    {
        T *buf = new T[this->size + a.size];
        for (int i = 0; i < this->size; i++)
            buf[i] = mas[i];
        int j = 0;
        for (int i = this->size; i < this->size + a.size; i++)
        {
            buf[i] = a.mas[j];
            j++;
        }
        delete[] mas;
        mas = new T[this->size + a.size];
        this->size += a.size;
        for (int i = 0; i< this->size; i++)
            mas[i] = buf[i];
        delete[] buf;
        return *this;
    }
    void Enter()
    {
        for (int i = 0; i < size; i++)
            std::cin >> mas[i];
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
            std::cout << mas[i] << ' ' << std::endl;
    }
};

int main()
{
    Massiv<int> mas1(5);
    Massiv<int> mas2(3);
    mas1.Enter();
    mas2.Enter();
    mas1 | mas2;
    mas2 = mas1;
    mas2.Print();
}
