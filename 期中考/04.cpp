/**
 * 功能說明：軍校體能測驗評分系統
 * 
 * 題目需求與功能描述：
 * 1. 輸入受測學生人數 N (1~30 人)。
 * 2. 依序輸入每位學生的三項體能測驗原始成績（非負整數）：
 *    - 伏地挺身次數 (次)
 *    - 仰臥起坐次數 (次)
 *    - 3000 公尺跑步時間 (秒)
 * 3. 體能計分換算標準函式：
 *    - 伏地挺身 (scorePushup) : >=60 次得 100 分; >=45 次得 80 分; >=30 次得 60 分; 其餘 0 分
 *    - 仰臥起坐 (scoreSitUp)  : >=60 次得 100 分; >=45 次得 80 分; >=30 次得 60 分; 其餘 0 分
 *    - 3000公尺 (scoreRunning): <=750 秒得 100 分; <=900 秒得 80 分; <=1080 秒得 60 分; 其餘 0 分
 *    - 總平均 (calculateTatal): 計算三項得分的算術平均 (a + b + c) / 3.0
 * 4. 輸出每位學生的各項原始數據、單項得分以及平均總分（取至小數點後兩位）。
 * 5. 使用 readInt() 搭配 stringstream 實作安全輸入防呆機制。
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

// ==========================================
// 函式宣告 (Function Prototypes)
// ==========================================
int scorePushup(int count);
int scoreSitUp(int count);
int scoreRunning(int seconds);
double calculateTatal(int a, int b, int c);
bool readInt(const string& prompt, int minimum, int maximum, int& value);

int main()
{
    const int MAX_STUDENTS = 30;     // 系統支援之最高學生人數
    int N = 0;                       // 實際輸入之學生人數
    int pushup[MAX_STUDENTS] = {0};  // 儲存伏地挺身次數
    int sitUp[MAX_STUDENTS] = {0};   // 儲存仰臥起坐次數
    int running[MAX_STUDENTS] = {0}; // 儲存跑步秒數

    cout << "===== 軍校體能測驗評分系統 =====\n";

    // 步驟 1：輸入學生人數 (1~30)
    if (!readInt("請輸入學生人數 (1~30): ", 1, MAX_STUDENTS, N))
        return 0;

    // 步驟 2：依序輸入每位學生的三項原始成績
    for (int i = 0; i < N; i++)
    {
        cout << "\n學生 " << i + 1 << " 的原始成績\n";
        if (!readInt("伏地挺身次數: ", 0, numeric_limits<int>::max(), pushup[i]))
            return 0;
        if (!readInt("仰臥起坐次數: ", 0, numeric_limits<int>::max(), sitUp[i]))
            return 0;
        if (!readInt("3000 公尺跑步秒數: ", 0, numeric_limits<int>::max(), running[i]))
            return 0;
    }

    // 步驟 3：計算各單項得分與總平均分，並輸出報告
    cout << "\n===== 體能測驗成績結果 =====\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < N; i++)
    {
        int a = scorePushup(pushup[i]);
        int b = scoreSitUp(sitUp[i]);
        int c = scoreRunning(running[i]);
        double total = calculateTatal(a, b, c);

        cout << "\n學生 " << i + 1 << "\n";
        cout << "伏地挺身: " << pushup[i] << " 次, 得分: " << a << "\n";
        cout << "仰臥起坐: " << sitUp[i] << " 次, 得分: " << b << "\n";
        cout << "3000 公尺: " << running[i] << " 秒, 得分: " << c << "\n";
        cout << "總分 (三項平均): " << total << "\n";
    }

    return 0;
}

/**
 * 函式名稱：scorePushup
 * 功能：依伏地挺身完成次數換算得分
 * 評分標準：>=60 次為 100分；>=45 次為 80分；>=30 次為 60分；否則為 0分
 */
int scorePushup(int count)
{
    if (count >= 60) return 100;
    if (count >= 45) return 80;
    if (count >= 30) return 60;
    return 0;
}

/**
 * 函式名稱：scoreSitUp
 * 功能：依仰臥起坐完成次數換算得分
 * 評分標準：>=60 次為 100分；>=45 次為 80分；>=30 次為 60分；否則為 0分
 */
int scoreSitUp(int count)
{
    if (count >= 60) return 100;
    if (count >= 45) return 80;
    if (count >= 30) return 60;
    return 0;
}

/**
 * 函式名稱：scoreRunning
 * 功能：依 3000 公尺跑步秒數換算得分（時間越短成績越佳）
 * 評分標準：<=750 秒(12分30秒)為 100分；<=900 秒(15分)為 80分；<=1080 秒(18分)為 60分；否則為 0分
 */
int scoreRunning(int seconds)
{
    if (seconds <= 750) return 100;
    if (seconds <= 900) return 80;
    if (seconds <= 1080) return 60;
    return 0;
}

/**
 * 函式名稱：calculateTatal
 * 功能：計算三項體能項目的平均得分
 * 參數：a, b, c 分別代表三項測驗的換算得分
 * 回傳值：三項測驗平均成績 (浮點數)
 */
double calculateTatal(int a, int b, int c)
{
    return (a + b + c) / 3.0;
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
            cout << "\n輸入已結束或無法繼續讀取, 程式結束。\n";
            return false;
        }

        istringstream check(input);
        int number;
        char extra;

        if (!(check >> number) || (check >> extra))
        {
            cout << "錯誤: 請在一行輸入一個整數!\n";
            continue;
        }

        if (number < minimum || number > maximum)
        {
            cout << "錯誤: 數值必須介於 " << minimum << " 與 " << maximum << " 之間!\n";
            continue;
        }

        value = number;
        return true;
    }
}
