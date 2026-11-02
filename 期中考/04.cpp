/**
 * C++ 模擬考題庫 - 第四題：軍校體能測驗評分系統
 * 
 * 【程式要求與評分標準】
 * 1. 輸入學生人數 N (1~30)，以三個容量為 30 的一維陣列分別儲存三項非負整數原始成績。
 * 2. 使用 for 依序輸入各學生的體測資料（下限 0，上限 numeric_limits<int>::max()）。
 * 3. 實作單項計分函式：
 *    - int scorePushup(int count)   : 60次以上→100分；45~59次→80分；30~44次→60分；0~29次→0分。
 *    - int scoreSitUp(int count)    : 60次以上→100分；45~59次→80分；30~44次→60分；0~29次→0分。
 *    - int scoreRunning(int seconds): 0~750秒→100分；751~900秒→80分；901~1080秒→60分；1081秒以上→0分。
 * 4. 實作 double calculateTatal(int a, int b, int c)：以三項換算得分的算術平均計算總分（保留題目原拼字）。
 * 
 * 【測試重點】
 * - 次數邊界：29→0分；30、44→60分；45、59→80分；60、61→100分。
 * - 秒數邊界：750→100分；751、900→80分；901、1080→60分；1081→0分。
 * - 範例驗算：伏地挺身60次(100)、仰臥起坐45次(80)、跑步1080秒(60) -> 總分 80.00。
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

// 函式原型宣告 (Function Prototypes)：calculateTatal 保留題目的原始拼字
int scorePushup(int count);
int scoreSitUp(int count);
int scoreRunning(int seconds);
double calculateTatal(int a, int b, int c);
bool readInt(const string& prompt, int minimum, int maximum, int& value);

int main()
{
    // 三個一維陣列保存原始資料（不直接存換算後的分數），同一索引代表同一位學生
    const int MAX_STUDENTS = 30;
    int N = 0;
    int pushup[MAX_STUDENTS] = {0};
    int sitUp[MAX_STUDENTS] = {0};
    int running[MAX_STUDENTS] = {0};

    cout << "===== 軍校體能測驗評分系統 =====\n";

    // 嚴格驗證人數為 1~30
    if (!readInt("請輸入學生人數 (1~30): ", 1, MAX_STUDENTS, N))
        return 0;

    // 逐一輸入各學生的三項非負整數原始成績 (索引 0 ~ N-1，顯示學生編號 i + 1)
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

    // 輸出各學生原始資料、單項得分與三項平均總分（顯示至小數點後兩位）
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
        cout << "仰臥起坐:" << sitUp[i] << " 次, 得分: " << b << "\n";
        cout << "3000 公尺:" << running[i] << " 秒,得分: " << c << "\n";
        cout << "總分 (三項平均):" << total << "\n";
    }

    return 0;
}

// 伏地挺身次數換算：次數越多分數越高，由高門檻往低門檻判斷，return 立即結束函式
int scorePushup(int count)
{
    if (count >= 60) return 100;
    if (count >= 45) return 80;
    if (count >= 30) return 60;
    return 0;
}

// 仰臥起坐次數換算：規則與伏地挺身相同，依題目要求獨立實作
int scoreSitUp(int count)
{
    if (count >= 60) return 100;
    if (count >= 45) return 80;
    if (count >= 30) return 60;
    return 0;
}

// 3000公尺跑步秒數換算：秒數越少分數越高，因此由最小秒數門檻 (750 -> 900 -> 1080) 往上判斷
int scoreRunning(int seconds)
{
    if (seconds <= 750) return 100;
    if (seconds <= 900) return 80;
    if (seconds <= 1080) return 60;
    return 0;
}

// 三項平均總分：傳入換算後的得分 a, b, c，使用 3.0 以浮點數除法計算，避免整數除法捨去小數
double calculateTatal(int a, int b, int c)
{
    return (a + b + c) / 3.0;
}

// 嚴格驗證每行一個整數：使用 getline 與 istringstream 拒絕文字、小數、多餘字元或超出範圍的輸入
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
            cout << "錯誤: 請在一行輸入一個整數! \n";
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
