#include <iostream>
#include <limits>

using namespace std;

int main()
{

    int age = 0;
    int height = 0;

    while (true)
    {
        cout << "Enter age:";

        if (!(cin >> age))
        {
            cout << "請輸入整數!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (age < 0 || age > 100)
        {
            cout << "Invalid Input\n";
        }
        else
        {
            break;
        }
    }

    if(age <= 11 || age>64)
    {
        cout << "Result: Not Allowed\n";
        return 0; 
    }



    while (true)
    {
        cout << "Enter height(cm):";

        if (!(cin >> height))
        {
            cout << "請輸入整數!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (height <= 0)
        {
            cout << "Invalid Input\n";
        }
        else
        {
            break;
        }
    }

    
    if (age >= 12 && age <= 64 && height >= 140)
    {
        cout << "Age:" << age <<"\n";
        cout << "Height:" << height <<"\n";
        cout << "Result: Allowed\n";
    }
    else if (age >= 12 && age <= 64 && height < 140)
    {
        cout << "Age:" << age <<"\n";
        cout << "Height:" << height <<"\n";
        cout << "Result: Not Allowed\n";
    }
    else
    {
        cout << "Age:" << age <<"\n";
        cout << "Height:" << height <<"\n";
        cout << "Result: Not Allowed\n";
    }

    return 0;
}