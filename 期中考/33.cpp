#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
char password[50]; //創建一個大小為50的陣列
int length = 0; //int 宣告密碼長度
bool hasUppercase = false; // 記錄是否曾找到大寫英文字母
bool hasNumber = false; //記錄是否曾找到數字
cout << "Enter password : "; // 螢幕顯示:輸入密碼
cin >> setw(50) >> password; // 最多讀取 49 個字元,保留 '\0' 空間
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