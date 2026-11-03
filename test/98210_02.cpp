#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int f= 0;
    int end = 1;   
    int days = 0;

    while (true)
        {
            cout << "Enter target:";
            if (!(cin >> f))
            {
                if (cin.eof() || cin.bad())
                {
                    return 0;
                }
                else
                {
                    cout << "Invalid Floor\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            else if (f < 0 || f > 10)
            {
                cout << "Invalid Floor";
                return 0;
            }
            else
            {
    }
            }
        }

       
    return 0;
}
