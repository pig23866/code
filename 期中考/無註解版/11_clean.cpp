#include <iostream>

using namespace std;

int main()
{
    int age = 0;

    while (true)
    {
        cout << "請輸入年齡:";

        if (!(cin >> age))
        {
            cout << "請輸入整數!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (age < 0 || age > 100)
        {
            cout << "錯誤:年齡必須介於0~100!\n";
        }
        else
        {
            break;
        }
    }

    if (age <= 5)
    {
        cout << "====Cinema Ticket====\n";
        cout << "Ticket Type: Free Ticket\n";
        cout << "Ticket Price: $0\n";
    }
    else if (age >= 6 && age <= 17)
    {
        cout << "====Cinema Ticket====\n";
        cout << "Ticket Type: Child Ticket\n";
        cout << "Ticket Price: $150\n";
    }
    else if (age >= 18 && age <= 64)
    {
        cout << "====Cinema Ticket====\n";
        cout << "Ticket Type: Adult Ticket\n";
        cout << "Ticket Price: $300\n";
    }
    else
    {
        cout << "====Cinema Ticket====\n";
        cout << "Ticket Type: Senior Ticket\n";
        cout << "Ticket Price: $150\n";
    }

    return 0;
}
