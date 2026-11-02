/**
 * C++ 模擬考題庫_2 - 題目三：密碼安全性系統
 * 
 * 【題目敘述】
 * 使用 char password[50] 儲存密碼，以 for 迴圈計算長度並檢查大寫英文字母和數字。
 * 
 * 【程式碼分段說明】
 * 1. 宣告字元陣列與檢查旗標：
 *    - password[50] 可容納 50 個字元 (索引 0~49)，C 風格字串結尾需保留 '\0'，最多存放 49 個密碼字元。
 *    - hasUppercase 與 hasNumber 兩個 bool 旗標初始設為 false，一旦找到對應字元即改為 true。
 * 2. 限制讀取長度：使用 <iomanip> 的 setw(50) 限制最多讀入 49 個字元並自動補上結尾標記 '\0'（假設密碼不含空白）。
 * 3. 逐字檢查並計算長度：for (int i = 0; password[i] != '\0'; i++) 遇到 '\0' 前持續執行 length++。
 * 4. 檢查大寫字母與數字：
 *    - 'A' ~ 'Z' 檢查大寫字母；'0' ~ '9' 檢查數字字元（單引號代表字元）。
 *    - 只要出現過一次即設為 true，後續字元不會將旗標改回 false。
 * 5. 顯示檢查結果：利用三元運算子 (條件 ? "yes" : "no") 輸出是否包含大寫與數字。
 * 6. 強弱密碼判定：同時滿足「長度 >= 8」、「含大寫字母」、「含數字」三項條件才輸出 Strong Password，否則為 Weak Password。
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char password[50];         // 創建一個大小為50的陣列
    int length = 0;            // int 宣告密碼長度
    bool hasUppercase = false; // 記錄是否曾找到大寫英文字母
    bool hasNumber = false;    // 記錄是否曾找到數字

    cout << "Enter password : ";  // 螢幕顯示:輸入密碼
    cin >> setw(50) >> password;  // 最多讀取 49 個字元,保留 '\0' 空間

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
