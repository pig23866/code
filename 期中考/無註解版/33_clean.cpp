#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char password[50];
    int length = 0;
    bool hasUppercase = false;
    bool hasNumber = false;

    cout << "Enter password : ";
    cin >> setw(50) >> password;

    for (int i = 0; password[i] != '\0'; i++)
    {
        length++;

        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            hasUppercase = true;
        }

        if (password[i] >= '0' && password[i] <= '9')
        {
            hasNumber = true;
        }
    }

    cout << "password length: " << length << endl;

    cout << "Contains uppercase: "
         << (hasUppercase ? "yes" : "no") << endl;

    cout << "Contains number: "
         << (hasNumber ? "yes" : "no") << endl;

    if (length >= 8 && hasUppercase && hasNumber)
    {
        cout << "Result:Strong Password" << endl;
    }
    else
    {
        cout << "Result:Weak Password" << endl;
    }

    return 0;
}
