#include <iostream>
#include <iomanip>

using namespace std;

// 計算所有選手完賽時間的平均秒數
double calculateAverage(int times[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += times[i];
    }
    return static_cast<double>(sum) / n;
}

// 找出最快完賽時間
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

// 統計合格選手人數（<= 7200 秒）
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

// 依秒數顯示獎牌等級
void showAward(int seconds)
{
    if (seconds <= 1800)
    {
        cout << "Gold";
    }
    else if (seconds <= 2400)
    {
        cout << "Silver";
    }
    else if (seconds <= 3000)
    {
        cout << "Bronze";
    }
    else
    {
        cout << "Participant";
    }
}

int main()
{
    int n;

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

    int times[30];

    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            cout << "Enter finish time for runner " << i + 1 << ": ";
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

    double avgTime = calculateAverage(times, n);
    int fastestTime = findFastest(times, n);
    int qualifiedCount = countQualified(times, n);

    cout << "======Marathon======" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Runner " << i + 1 << " :" << times[i] << " sec, ";
        showAward(times[i]);
        cout << endl;
    }
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Average time: " << avgTime << " sec" << endl;

    // 【並列全列出】：遍歷印出所有並列最快時間的選手
    cout << "Fastest Runner(s): ";
    bool first = true;
    for (int i = 0; i < n; i++)
    {
        if (times[i] == fastestTime)
        {
            if (!first)
            {
                cout << ", ";
            }
            cout << "Runner " << i + 1;
            first = false;
        }
    }
    cout << endl;

    cout << "Fastest time: " << fastestTime << " sec " << endl;
    cout << "Qualified runners: " << qualifiedCount << endl;

    return 0;
}

