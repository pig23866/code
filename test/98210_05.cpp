#include <iostream>
#include <iomanip>

using namespace std;

// ==========================================
// 函式實作 (Function Implementations)
// ==========================================

/**
 * 函式名稱：calculateAverage
 * 功能：計算所有選手完賽時間的平均秒數
 * 參數：times[] - 完賽時間陣列；n - 選手人數
 * 回傳值：平均完賽時間 (秒，浮點數)
 */
double calculateAverage(int times[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += times[i];
    }
    return static_cast<double>(sum) / n;
}

/**
 * 函式名稱：findFastest
 * 功能：找出最快完賽時間 (秒數最小者)
 * 參數：times[] - 完賽時間陣列；n - 選手人數
 * 回傳值：最快完賽秒數
 */
int findFastest(int times[], int n)
{
    int fastest = times[0];
    for (int i = 1; i < n; i++)
    {
        if (times[i] < fastest)
        {
            fastest = times[i];
        }
    }
    return fastest;
}

/**
 * 函式名稱：countQualified
 * 功能：計算合格選手人數（合格標準為 2 小時以內，即 <= 7200 秒）
 * 參數：times[] - 完賽時間陣列；n - 選手人數
 * 回傳值：合格選手人數
 */
int countQualified(int times[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (times[i] <= 7200)
        {
            count++;
        }
    }
    return count;
}

/**
 * 函式名稱：showAward
 * 功能：依完賽秒數判定並顯示獎牌等級或不合格
 * 區間規則：
 *  - <= 3600 秒 (1小時以內)：Gold Medal (金牌)
 *  - 3601 ~ 5400 秒 (1.5小時以內)：Silver Medal (銀牌)
 *  - 5401 ~ 7200 秒 (2小時以內)：Bronze Medal (銅牌)
 *  - > 7200 秒：Not Qualified / Disqualified (不合格)
 */
void showAward(int seconds)
{
    if (seconds <= 3600)
    {
        cout << "Gold Medal";
    }
    else if (seconds <= 5400)
    {
        cout << "Silver Medal";
    }
    else if (seconds <= 7200)
    {
        cout << "Bronze Medal";
    }
    else
    {
        cout << "Not Qualified";
    }
}

// ==========================================
// 主程式 (Main)
// ==========================================
int main()
{
    int n;

    // 1. 輸入選手人數 N (範圍 1～30)
    while (true)
    {
        cout << "Enter number of runners (1-30): ";
        if (!(cin >> n))
        {
            cout << "Please enter an integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (n < 1 || n > 30)
        {
            cout << "Number of runners must be between 1 and 30.\n";
            continue;
        }
        break;
    }

    // 2. 使用一維陣列 times[30] 儲存完賽時間
    int times[30];

    // 3. 使用 for 迴圈依序輸入每位選手的完賽時間
    // 4. 每位選手的完賽時間必須大於 0
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            cout << "Enter finish time for runner " << i + 1 << " (seconds): ";
            if (!(cin >> times[i]))
            {
                cout << "Please enter an integer.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (times[i] <= 0)
            {
                cout << "Finish time must be greater than 0.\n";
                continue;
            }
            break;
        }
    }

    // 呼叫函式計算統計資料
    double avgTime = calculateAverage(times, n);
    int fastestTime = findFastest(times, n);
    int qualifiedCount = countQualified(times, n);

    // 7. 若最快完賽時間有多位選手並列，以最先輸入的選手作為輸出對象
    int fastestRunner = 1;
    for (int i = 0; i < n; i++)
    {
        if (times[i] == fastestTime)
        {
            fastestRunner = i + 1;
            break; // 找到第一個並列最快的選手即中斷
        }
    }

    // 8. 找出最慢的選手時間
    int slowestTime = times[0];
    for (int i = 1; i < n; i++)
    {
        if (times[i] > slowestTime)
        {
            slowestTime = times[i];
        }
    }

    // 輸出選手成績與獎牌報表
    cout << "\nRunner | Time (s) | Award" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " | "
             << times[i] << " | ";
        showAward(times[i]);
        cout << endl;
    }

    // 6. 所有完賽時間及平均完賽時間皆以秒顯示（平均時間格式化為小數點後兩位）
    cout << fixed << setprecision(2);
    cout << "\nAverage time: " << avgTime << " seconds" << endl;
    cout << "Fastest time: " << fastestTime << " seconds (Runner " << fastestRunner << ")" << endl;
    cout << "Slowest time: " << slowestTime << " seconds" << endl;
    cout << "Qualified runners: " << qualifiedCount << endl;

    return 0;
}

