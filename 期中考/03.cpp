/**
 * 功能說明：校園停車場車位管理系統
 * 
 * 題目需求與功能描述：
 * 1. 輸入車位總數 N (介於 1~30 之間)，並進行安全輸入驗證。
 * 2. 依序輸入每個車位的佔用狀態：
 *    - 0 代表 Available（可用 / 空位）
 *    - 1 代表 Occupied（已佔用）
 * 3. 模組化函式統計：
 *    - countOccupied()  : 計算已佔用的車位總數
 *    - countAvailable() : 計算剩餘可用的空車位總數
 *    - calculateUsage() : 計算車位使用率百分比 (已佔用 / 總數 * 100%)
 * 4. 根據車位使用率判定停車場狀態：
 *    - 100%      : Parking Full (全滿)
 *    - >= 80%    : Almost Full (即將客滿)
 *    - < 80%     : Spaces Available (尚有空位)
 * 5. 列印所有可使用的空車位編號（若全部被佔用則顯示「無」）。
 * 6. 使用 readInt() 搭配 stringstream 實作強健的整行輸入防呆機制。
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// ==========================================
// 函式宣告 (Function Prototypes)
// ==========================================
int countOccupied(int parking[], int n);
int countAvailable(int parking[], int n);
double calculateUsage(int parking[], int n);
bool readInt(const string& prompt, int minimum, int maximum, int& value);

int main()
{
    const int MAX_SPACES = 30;       // 系統支援之車位最大容量
    int N = 0;                       // 實際輸入之車位總數
    int parking[MAX_SPACES] = {0};   // 記錄車位狀態陣列 (0: 可用, 1: 佔用)

    cout << "===== 校園停車場車位管理系統 =====\n";

    // 步驟 1：輸入車位總數 (1~30)
    if (!readInt("請輸入車位總數 (1~30): ", 1, MAX_SPACES, N))
        return 0;

    // 步驟 2：依序輸入各車位目前的狀態
    for (int i = 0; i < N; i++)
    {
        cout << "車位 " << i + 1 << "\n";
        if (!readInt("請輸入狀態 (0=Available, 1=Occupied): ", 0, 1, parking[i]))
            return 0;
    }

    // 步驟 3：呼叫函式計算統計數據
    int occupied = countOccupied(parking, N);
    int available = countAvailable(parking, N);
    double usage = calculateUsage(parking, N);

    // 步驟 4：輸出車位統計數據報告
    cout << "\n===== 車位統計結果 =====\n";
    cout << "車位總數: " << N << "\n";
    cout << "已占用車位數: " << occupied << "\n";
    cout << "剩餘車位數: " << available << "\n";
    cout << fixed << setprecision(2);
    cout << "使用率: " << usage << "%\n";

    // 步驟 5：判定並輸出停車場目前總體狀態
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

    // 步驟 6：列出所有可使用的空車位編號
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

/**
 * 函式名稱：countOccupied
 * 功能：計算並回傳停車場中「已佔用」(狀態為 1) 的車位數量
 * 參數：parking[] - 車位狀態陣列；n - 車位總數
 * 回傳值：已佔用車位個數
 */
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

/**
 * 函式名稱：countAvailable
 * 功能：計算並回傳停車場中「剩餘可用」(狀態為 0) 的車位數量
 * 參數：parking[] - 車位狀態陣列；n - 車位總數
 * 回傳值：剩餘空車位個數
 */
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

/**
 * 函式名稱：calculateUsage
 * 功能：計算停車場車位的使用率百分比
 * 參數：parking[] - 車位狀態陣列；n - 車位總數
 * 回傳值：使用率百分比數值 (0.0 ~ 100.0)
 */
double calculateUsage(int parking[], int n)
{
    return countOccupied(parking, n) * 100.0 / n;
}

/**
 * 函式名稱：readInt
 * 功能：安全輸入輔助函式，確保使用者在單行輸入介於指定範圍 [minimum, maximum] 的有效整數
 * 參數：
 *   - prompt  : 提示文字
 *   - minimum : 允許輸入的最小值
 *   - maximum : 允許輸入的最大值
 *   - value   : 傳址回傳讀取到的有效整數值
 * 回傳值：成功讀取回傳 true，若輸入流中斷或 EOF 回傳 false
 */
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

        // 檢查是否成功讀取一個整數，且其後無多餘字元
        if (!(check >> number) || (check >> extra))
        {
            cout << "錯誤:請在一行輸入一個整數!\n";
            continue;
        }

        // 檢查範圍是否落在 [minimum, maximum] 之間
        if (number < minimum || number > maximum)
        {
            cout << "錯誤:數值必須介於 " << minimum << " 與 " << maximum << " 之間!\n";
            continue;
        }

        value = number;
        return true;
    }
}
