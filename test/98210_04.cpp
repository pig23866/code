#include <iostream>

using namespace std;


int calculateFine(int days)
{
    if (days <= 0)
    {
        return 0;
    }
    else if (days <= 5)
    {
        return days * 2;
    }
    else if (days > 5 && days <= 10)
    {
        return 10 + ((days - 5) * 5);
    }
    else
    {
        return 35 + ((days - 10) * 10);
    }
}

int calcuatetotalFine(int fine[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += fine[i];
    }
    return total;
}

int countOverdue(int overdue[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (overdue[i] > 0)
        {
            count++;
        }
    }
    return count;
}



int calculateTotalFine(int fine[], int n)
{
    return calcuatetotalFine(fine, n);
}

int main()
{
    int n;

    while (true)
    {
        cout << "Enter number of books (1-30): ";
        if (!(cin >> n))
        {
            cout << "Please enter an integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (n < 1 || n > 30)
        {
            cout << "Number of books must be between 1 and 30.\n";
            continue;
        }
        break;
    }

    int overdue[30];
    int fine[30];

    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            cout << "Enter overdue days for book " << i + 1 << ": ";
            if (!(cin >> overdue[i]))
            {
                cout << "Please enter an integer.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (overdue[i] < 0)
            {
                cout << "Overdue days cannot be negative.\n";
                continue;
            }
            break;
        }

        fine[i] = calculateFine(overdue[i]);
    }

    cout << "=======Overdue Report========" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Book " << i + 1 << ": " << overdue[i] << " day, Fine: $" << fine[i] << endl;
    }

    int overdueCount = countOverdue(overdue, n);
    int totalFine = calcuatetotalFine(fine, n);

    cout << "\nOverdue books: " << overdueCount << endl;
    cout << "Total fine: " << totalFine << endl;

    return 0;
}
