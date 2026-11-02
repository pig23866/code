/**
 * 功能說明：密碼安全性強度檢測系統
 * 
 * 題目需求與功能描述：
 * 1. 讀取使用者輸入的密碼字串（使用 setw(50) 防止緩衝區溢位，保留結尾 '\0' 空間）。
 * 2. 逐字元走訪檢查密碼安全性：
 *    - 計算密碼總長度 (length)。
 *    - 檢查是否包含至少一個大寫英文字母 ('A'~'Z')。
 *    - 檢查是否包含至少一個數字字元 ('0'~'9')。
 * 3. 輸出各項檢驗指標：
 *    - password length: 密碼字數
 *    - Contains uppercase: yes / no
 *    - Contains number: yes / no
 * 4. 強度判定條件：
 *    - 若「長度 >= 8」且「含有大寫字母」且「含有數字」，判定為 Strong Password。
 *    - 若有任一條件不符合，判定為 Weak Password。
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char password[50];         // 創建一個大小為50的字元陣列儲存密碼
    int length = 0;            // int 宣告密碼長度計數器
    bool hasUppercase = false; // 記錄是否曾找到大寫英文字母 (true/false)
    bool hasNumber = false;    // 記錄是否曾找到數字 (true/false)

    // ==========================================
    // 第一部分：輸入密碼
    // ==========================================
    cout << "Enter password : ";
    cin >> setw(50) >> password; // 最多讀取 49 個字元,保留 '\0' 空間避免溢位

    // ==========================================
    // 第二部分：逐字元分析密碼內容
    // ==========================================
    for (int i = 0; password[i] != '\0'; i++)
    {
        length++; // 累計密碼長度

        // 檢查是否為大寫英文字母
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            hasUppercase = true;
        }

        // 檢查是否為數字字元
        if (password[i] >= '0' && password[i] <= '9')
        {
            hasNumber = true;
        }
    }

    // ==========================================
    // 第三部分：顯示檢測指標與強度結果
    // ==========================================
    cout << "password length: " << length << endl;
    cout << "Contains uppercase: " << (hasUppercase ? "yes" : "no") << endl;
    cout << "Contains number: " << (hasNumber ? "yes" : "no") << endl;

    // 綜合強度判定（三個條件皆滿足才算強密碼）
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
