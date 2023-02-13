//Создать класс для работы с текстовым файлом.
//В файл записать название книги, фамилию автора и год издания книги. 
//Переписать в новый файл все книги после указанного года (год вводится с клавиатуры).
//Перегрузить ввод/вывод.

#include <iostream>
#include <string>
#include <fstream>
using namespace std ;

class TextFile
{
private:
    string _author;
    string _book;
    int _year;
public:
    TextFile() = default;
    TextFile(const string author, const string book, int year)
    {
        _author = author;
        _book = book;
        _year = year;
    }
    ~TextFile() = default;
    void WriteInFile();
    static void RewriteByYear();
    friend ostream& operator<<(ostream&, const TextFile&);
    friend istream& operator>>(istream&, TextFile&);
};

ostream& operator<<(ostream&out, const TextFile& file)
{
    return out << file._author << " " << file._book << " " << file._year << endl;
}

istream& operator>>(istream& in, TextFile& file)
{
    in >> file._author >> file._book >> file._year;
    return in;
}

void TextFile :: WriteInFile()
{
    ofstream file("file.txt", ios::app);
    file << '\n' << this->_author << ' ' << this->_book << ' ' << this->_year;
    file.close();
}

void TextFile :: RewriteByYear()
{
    ifstream file("file.txt");
    ofstream tmp("tmp.txt", ios::app);
    if (!file.is_open())
        cout << "Ошибка открытия файла";
    cout << "Введите нужный год: ";
    int nyear;
    while (1)
    {
        try
        {
            cin >> nyear;
            if (cin.fail())
                throw 1.0f;
            if (nyear <= 0 || nyear > 2023)
                throw 1;
            break;
        }
        catch (int)
        {
            cout << "Введен неверный год. Введите еще раз: ";
        }
        catch (float)
        {
            cout << "Введен неверный год. Введите еще раз: ";
            cin.clear();
            fflush(stdin);
        }
    }
    string author, book;
    int year;
    while(!file.eof())
    {
        file >> author >> book >> year;
        if(year >= nyear)
            tmp << '\n' << ' ' << author << ' ' << book << ' ' << year;
    }
    rename("tmp.txt", "newFile.txt");
    file.close();
    tmp.close();
}

int main()
{
   //TextFile book;
   //cin >> book;
   //cout << book;
   //book.WriteInFile();
   TextFile::RewriteByYear();
}
