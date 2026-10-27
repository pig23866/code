#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;
int main() {
    // 設定為UTF-8編碼
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001); 
    int n;
    int passCount = 0;
    int failCount = 0;
    for (int i = 0; i < 1; i++) {
        cout << "請輸入學生數量: ";
        cin >> n;
        if (n < 0 || n > 30) {
            cout << "【錯誤】！" << endl;
            i--; 
        }
    }
    
        
    int scores[n];
    cout << "=== 請輸入" << n <<"位學生的成績 ===" << endl;
    for (int i = 0; i < n ; i++) {
        cout << "請輸入學生 " << (i + 1) << " 的成績: ";
        cin >> scores[i];
        if (scores[i] < 0 || scores[i] > 100) {
            cout << "【錯誤】成績必須介於 0 到 100 之間，請重新輸入！" << endl;
            i--;
        }
    }

    cout << endl;

    for (int i = 0; i < n ; i++) {
        if (scores[i] >= 60) {
            passCount++; 
            cout << "Student"<< (i + 1) <<":Pass"<< endl;
            } 
        else {
            failCount++;
            cout << "Student"<< (i + 1) <<":Fail"<< endl;   
        }
    }
    cout << endl;
    cout << "Total Pass: " << passCount << endl;
    cout << "Total Fail: " << failCount << endl;   
    return 0;
}
