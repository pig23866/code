/**
 * C++ 模擬考題庫 - 第三題：校園停車場車位管理系統
 * 
 * 【情境說明與程式要求】
 * 校園停車場需要統計車位占用狀況、使用率及可使用的車位編號（0 代表 Available 可使用，1 代表 Occupied 已占用）。
 * 1. 輸入車位總數 N (1~30)，使用容量 30 的一維陣列 parking[30] 儲存狀態。
 * 2. 使用 for 依序輸入前 N 格車位狀態，只能輸入 0 或 1。
 * 3. 實作 int countOccupied(int parking[], int n)：計算已占用車位數。
 * 4. 實作 int countAvailable(int parking[], int n)：計算剩餘車位數。
 * 5. 實作 double calculateUsage(int parking[], int n)：計算使用率（已占用車位數 ÷ N × 100%）。
 * 6. 使用 if ... else if ... else 判斷停車場狀態：
 *    - 100%           : Parking Full
 *    - 80% ~ 未滿 100% : Almost Full
 *    - 未滿 80%        : Spaces Available
 * 7. 列出所有可使用的車位編號；沒有空位時顯示「無」。
 * 
 * 【測試重點】
 * - N = 1, 狀態 0 -> 已占用/剩餘 0/1, 使用率 0.00%, Spaces Available, 可用編號: 1
 * - N = 1, 狀態 1 -> 已占用/剩餘 1/0, 使用率 100.00%, Parking Full, 可用編號: 無
 * - N = 5, 狀態 1,1,1,1,0 -> 已占用/剩餘 4/1, 使用率 80.00%, Almost Full, 可用編號: 5
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// 函式原型宣告 (Function Prototypes)：先告知編譯器參數與回傳型別，實際定義放在 main() 後方
int countOccupied(int parking[], int n);
int countAvailable(int parking[], int n);
double calculateUsage(int parking[], int n);
bool readInt(const string& prompt, int minimum, int maximum, int& value);

int main()
{
    // 建立容量為 30 的一維陣列，{0} 將所有元素初始化為 0，實際只處理已輸入的前 N 格
    const int MAX_SPACES = 30;
    int N = 0;
    int parking[MAX_SPACES] = {0};

    cout << "===== 校園停車場車位管理系統 =====\n";

    // 驗證車位總數 (只接受 1~30 的整數，確保不超出陣列容量，也避免使用率計算時除以 0)
    if (!readInt("請輸入車位總數 (1~30): ", 1, MAX_SPACES, N))
        return 0;

    // 使用 for 逐格輸入車位狀態 (索引 i 取 0 ~ N-1，顯示車位編號時使用 i + 1)
    for (int i = 0; i < N; i++)
    {
        cout << "車位 " << i + 1 << "\n";
        if (!readInt("請輸入狀態 (0=Available, 1=Occupied): ", 0, 1, parking[i]))
            return 0;
    }

    // 呼叫三個統計函式計算已占用數、剩餘數及使用率
    int occupied = countOccupied(parking, N);
    int available = countAvailable(parking, N);
    double usage = calculateUsage(parking, N);

    // 輸出車位統計結果（使用 fixed 與 setprecision(2) 將使用率顯示為小數點後兩位）
    cout << "\n===== 車位統計結果 =====\n";
    cout << "車位總數: " << N << "\n";
    cout << "已占用車位數: " << occupied << "\n";
    cout << "剩餘車位數: " << available << "\n";
    cout << fixed << setprecision(2);
    cout << "使用率: " << usage << "%\n";

    // 使用 if、else if、else 判斷停車場狀態（必須先判斷 100% 滿位，再判斷 80% 門檻）
    if (usage == 100.0)
    {
        cout << "停車場狀態: Parking Full\n";
    }
    else if (usage >= 80.0)
    {
        cout << "停車場狀態: Almost Full\n";
    }
    else
    {
        cout << "停車場狀態: Spaces Available\n";
    }

    // 列出所有可使用的車位編號（不能在找到第一個空位後就 break，須列出全部空位）
    cout << "可使用的車位編號: ";
    if (available == 0)
    {
        cout << "無\n";
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (parking[i] == 0)
                cout << i + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}

// 計算已占用車位數：只掃描前 n 格，每遇到 parking[i] == 1 就將 count 加 1
int countOccupied(int parking[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (parking[i] == 1)
            count++;
    }
    return count;
}

// 計算剩餘車位數：只計算狀態為 0 (Available) 的車位，occupied + available == N 必成立
int countAvailable(int parking[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (parking[i] == 0)
            count++;
    }
    return count;
}

// 計算使用率：先乘上 100.0 轉為浮點數運算再除以 n，避免整數除法先捨去小數
double calculateUsage(int parking[], int n)
{
    return countOccupied(parking, n) * 100.0 / n;
}

// 輸入驗證與提前結束：使用 getline 與 istringstream 嚴格驗證整行只有一個合法整數且在範圍內
bool readInt(const string& prompt, int minimum, int maximum, int& value)
{
    string input;
    while (true)
    {
        cout << prompt;
        if (!getline(cin, input))
        {
            cout << "\n輸入已結束或無法繼續讀取,程式結束。\n";
            return false;
        }

        istringstream check(input);
        int number;
        char extra;

        // check >> number 必須讀出合法 int；若 check >> extra 還能讀到非空白字元代表有多餘內容
        if (!(check >> number) || (check >> extra))
        {
            cout << "錯誤:請在一行輸入一個整數!\n";
            continue;
        }

        // 檢查數值範圍是否介於 minimum 與 maximum 之間
        if (number < minimum || number > maximum)
        {
            cout << "錯誤:數值必須介於 " << minimum << " 與 " << maximum << " 之間!\n";
            continue;
        }

        value = number; // 透過傳參考 (int& value) 直接寫入主程式變數
        return true;
    }
}
