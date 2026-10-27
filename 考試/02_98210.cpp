#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;
int main() {
    // 設定為UTF-8編碼
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int choice=-1;
    int total=0;
    cout << "1. Water 20" << endl;
        cout << "2. Tea 30 " << endl;
        cout << "3. Coffee 45" << endl;
        cout << "0. 離開" << endl;
    while (choice != 0) {
        cout << "請選擇：";
        cin >> choice;

        switch (choice) {
            case 1: {

                break;
            }

            case 2: {

                break;
            }

            case 3: {

               break; 
            }

            case 4: {
                
                break;
            }

            case 5: {
                
                break;
            }

            case 0:
                cout << "\n感謝使用，系統已離開！" << endl;
                break;

            default:
                cout << "\n【錯誤】無效的選項，請重新輸入！" << endl;
                break;
        }
    }

    return 0;
}
