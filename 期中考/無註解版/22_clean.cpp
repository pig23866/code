#include <iostream>

using namespace std;

int main()
{

    double target = 0;
    double amount = 0;
    double total = 0;
    int days = 0;

    while (true)
    {
        cout << "Enter saving target: ";
        if (!(cin >> target))
        {
            cout << "Invalid Target" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (target <= 0)
        {
            cout << "Invalid Target" << endl;
            continue;
        }
        break;
    }

    while (total < target)
    {
        cout << "Enter daily deposit: ";
        if (!(cin >> amount))
        {
            cout << "Invalid Amount" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (amount <= 0)
        {
            cout << "Invalid Amount" << endl;
            continue;
        }

        total += amount;
        days++;

        cout << "Current total: " << total << endl;
    }

    cout << "Goal reached!" << endl;
    cout << "Days: " << days << endl;
    cout << "Total savings: " << total << endl;

    return 0;
}
