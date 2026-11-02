#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

int countOccupied(int parking[], int n);
int countAvailable(int parking[], int n);
double calculateUsage(int parking[], int n);
bool readInt(const string& prompt, int minimum, int maximum, int& value);

int main()
{

    const int MAX_SPACES = 30;
    int N = 0;
    int parking[MAX_SPACES] = {0};

    cout << "===== 校園停車場車位管理系統 =====\n";

    if (!readInt("請輸入車位總數 (1~30): ", 1, MAX_SPACES, N))
        return 0;

    for (int i = 0; i < N; i++)
    {
        cout << "車位 " << i + 1 << "\n";
        if (!readInt("請輸入狀態 (0=Available, 1=Occupied): ", 0, 1, parking[i]))
            return 0;
    }

    int occupied = countOccupied(parking, N);
    int available = countAvailable(parking, N);
    double usage = calculateUsage(parking, N);

    cout << "\n===== 車位統計結果 =====\n";
    cout << "車位總數: " << N << "\n";
    cout << "已占用車位數: " << occupied << "\n";
    cout << "剩餘車位數: " << available << "\n";
    cout << fixed << setprecision(2);
    cout << "使用率: " << usage << "%\n";

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

double calculateUsage(int parking[], int n)
{
    return countOccupied(parking, n) * 100.0 / n;
}

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

        if (!(check >> number) || (check >> extra))
        {
            cout << "錯誤:請在一行輸入一個整數!\n";
            continue;
        }

        if (number < minimum || number > maximum)
        {
            cout << "錯誤:數值必須介於 " << minimum << " 與 " << maximum << " 之間!\n";
            continue;
        }

        value = number;
        return true;
    }
}
