#include <iostream>

using namespace std;

int main()
{
    int currentFloor = 1;
    int targetFloor = 0;
    cout << "Current Floor: 1\n";
    while (true)
    {
        cout << "Enter target:";
        if (!(cin >> targetFloor))
        {
            if (cin.eof() || cin.bad())
            {
                return 0;
            }
            cout << "Invalid Floor" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (targetFloor < 1 || targetFloor > 10)
        {
            cout << "Invalid Floor" << endl;
            continue;
        }

        if (targetFloor == currentFloor)
        {
            cout << "Arrived at Floor " << currentFloor << endl;
        }
        else
        {
            while (currentFloor != targetFloor)
            {
                if (targetFloor > currentFloor)
                {
                    currentFloor++;
                }
                else
                {
                    currentFloor--;
                }
                cout << "Moving to " << currentFloor << endl;
            }

            cout << "Arrived at Floor " << currentFloor << endl;
        }

        if (currentFloor == 1)
        {
            break;
        }
    }

    return 0;
}
