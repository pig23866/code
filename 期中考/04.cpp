#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

// 函式宣告
int scorePushup(int count);
int scoreSitUp(int count);
int scoreRunning(int seconds);
double calculateTatal(int a, int b, int c);
bool readInt(const string& prompt, int minimum, int maximum, int& value);

int main()
{
    const int MAX_STUDENTS = 30;
    int N = 0;
    int pushup[MAX_STUDENTS] = {0};
    int sitUp[MAX_STUDENTS] = {0};
    int running[MAX_STUDENTS] = {0};

    cout << "===== 軍校體能測驗評分系統 =====\n";

    // 輸入學生人數
    if (!readInt("請輸入學生人數 (1~30): ", 1, MAX_STUDENTS, N))
        return 0;

    // 輸入每位學生的原始成績
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

    // 計算並輸出成績結果
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

// 伏地挺身計分
int scorePushup(int count)
{
    if (count >= 60) return 100;
    if (count >= 45) return 80;
    if (count >= 30) return 60;
    return 0;
}

// 仰臥起坐計分
int scoreSitUp(int count)
{
    if (count >= 60) return 100;
    if (count >= 45) return 80;
    if (count >= 30) return 60;
    return 0;
}

// 3000公尺跑步計分
int scoreRunning(int seconds)
{
    if (seconds <= 750) return 100;
    if (seconds <= 900) return 80;
    if (seconds <= 1080) return 60;
    return 0;
}

// 計算三項平均總分
double calculateTatal(int a, int b, int c)
{
    return (a + b + c) / 3.0;
}

// 安全讀取介於 minimum 與 maximum 間的整數
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
