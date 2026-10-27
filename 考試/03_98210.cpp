#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;
int main() {
    // 設定為UTF-8編碼
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    char password[50];
    cout << "Enter password : ";
    cin >> password;

    int length = 0;
    bool hasUpper = false;
    bool hasDigit = false;

    for (int i = 0; password[i] != '\0'; i++) {
        length++;
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = true;
        }
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = true;
        }
    }

    cout << "password length: " << length << endl;
    cout << "Contains uppercase: " << (hasUpper ? "yes" : "no") << endl;
    cout << "Contains number: " << (hasDigit ? "yes" : "no") << endl;

    if (length >= 8 && hasUpper && hasDigit) {
        cout << "Result:Strong Password" << endl;
    } else {
        cout << "Result:Weak Password" << endl;
    }

    return 0;
}