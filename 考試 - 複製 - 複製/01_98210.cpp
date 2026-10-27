#include <iostream>
using namespace std;

int main() {
    int n;
    for (int i = 0; i < 1; i++) {
        cout << "請輸入年齡: ";
        cin >> n;
        if (n < 0 || n > 100) {
            cout << "invalid age" << endl;
            i--; 
        }
    }
    if (n <= 5) {
        cout << "Ticket: " <<"free ticket" << endl;
        cout << "Ticket Price: " << 0 << endl;
    } else if (n < 18) {
        cout << "Ticket: " <<"child ticket" << endl;
        cout << "Ticket Price: " << 150 << endl;
    } else if (n < 65) {
        cout << "Ticket: " <<"adult ticket" << endl;
        cout << "Ticket Price: " << 300 << endl;
    } else {
        cout << "Ticket: " <<"senior ticket" << endl;
        cout << "Ticket Price: " << 150 << endl;
    }

    return 0;
}
