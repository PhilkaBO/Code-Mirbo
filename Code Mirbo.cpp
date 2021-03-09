
#include <iostream>
#include <string>

using namespace std;

class Mirabo
{
private:
    int static const cols = 6;
    int static const rows = 5;

    char table_date[rows][cols] =
    {
        {'a', 'b', 'c', 'd', 'e', 'f'},
        {'g', 'h', 'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p', 'q', 'r'},
        {'s', 't', 'u', 'v', 'w', 'x'},
        {'y', 'z', ' ', '*', '*', '*'}
    };

    //Поиск буквы в таблице Мирабо
    string FindDate(char letter);
    //Привидение строки к нижнему регистру
    string ToLower(string str);
public:
    //Шифровщик
    string Encoder(string str);
    //Дешифровщик
    string Decoder(string str);
};

int main()
{
    //Леденцов Владислав Павлович
    //Практическая работа 1

    Mirabo code;
    string str;
    string mode;

    string repeat;

    cout << "\t\t\tCODE MIRABO\n\n";

    do {
        do
        {
            //Меню
            cout << "1.Encrypt message" << endl;
            cout << "2.Decrypt message" << endl;
            cout << "3.Exit" << endl;
            cout << "Select the mode: ";
            cin >> mode;
        } while (mode != "1" && mode != "2" && mode != "3");

        //Зашифровка сообщения
        if (mode == "1")
        {

            cout << "\nEnter message to encrypt: ";
            _flushall();
            cin.get();
            getline(cin, str);
            cout << "Result message: " << code.Encoder(str) << endl;
            cout << "\nWant to try again?(y/n) ";
            cin >> repeat;
        }
        //Расшифровка сообщения
        else if (mode == "2")
        {
            _flushall();
            cout << "\nEnter message to decrypt: ";
            cin.get();
            getline(cin, str);
            cout << "Result message: " << code.Decoder(str) << endl;
            cout << "\nWant to try again?(y/n) ";
            cin >> repeat;
        }
        //Выход
        else
        {
            return 0;
        }
        cout << "\n\n\n";
    } while (repeat == "Y" || repeat == "y");
}

string Mirabo::FindDate(char letter)
{
    string str = "Incorrect data entered!";
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < cols; k++)
        {
            if (letter == table_date[i][k])
            {
                str = to_string(i) + to_string(k);
                return str;
            }
        }
    }
    return str;
}

string Mirabo::ToLower(string str)
{
    string lowerstr;
    for (int i = 0; i < str.size(); i++)
    {
        lowerstr.push_back(tolower(str[i]));
    }
    return lowerstr;
}

string Mirabo::Encoder(string str)
{
    str = ToLower(str);
    
    string resultstr;

    for (int i = 0; i < str.size(); i++)
    {
        if (i != 0) { resultstr.push_back('.'); }
        if (FindDate(str[i]) == "Incorrect data entered!") { return "Incorrect data entered!"; }
        resultstr = resultstr + FindDate(str[i]);
    }
    
    return resultstr;
}

string Mirabo::Decoder(string str)
{
    int cols = -1;
    int rows = -1;

    string result;

    for (int i = 0; i < str.size() - 1; i = i + 3)
    {
        rows = ((int)str[i]) - 48;
        cols = ((int)str[i + 1]) - 48;

        if (cols < 0 || cols >= this->cols) { return "Incorrect data entered!"; }
        if (rows < 0 || rows >= this->rows) { return "Incorrect data entered!"; }
        if (table_date[rows][cols] == '*') { return "Incorrect data entered!"; }

        result.push_back(table_date[rows][cols]);
    }
    return result;
}
