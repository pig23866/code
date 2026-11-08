#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // 1. 使用一維整數陣列 Temperature[n] 儲存 (n = 7)
    const int n = 7;
    int Temperature[n];

    // 2. 使用 for 迴圈依序讀取 7 日資料
    cout << "Input Temperature" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Day " << (i + 1) << " Temperature: ";
        cin >> Temperature[i];
    }

    int sum = 0;
    int hotCount = 0; // 4. 統計氣溫 > 35 度的天數
    int maxTemp = Temperature[0];
    int minTemp = Temperature[0];
    int hottestDay = 1; // 5. 最高溫度對應天數 (預設第 1 天)

    for (int i = 0; i < n; i++) {
        sum += Temperature[i];

        // 4. 統計氣溫 > 35 度
        if (Temperature[i] > 35) {
            hotCount++;
        }

        // 3 & 5. 找最高溫與對應天數 (使用 > 判斷，若有並列則會保留最早的那天)
        if (Temperature[i] > maxTemp) {
            maxTemp = Temperature[i];
            hottestDay = i + 1;
        }

        // 3. 找最低溫
        if (Temperature[i] < minTemp) {
            minTemp = Temperature[i];
        }
    }

    // 3. 計算平均氣溫
    double average = static_cast<double>(sum) / n;

    // 6. 平均氣溫顯示到小數點後兩位
    cout << fixed << setprecision(2);
    cout << "Average Temperature: " << average << " C" << endl;
    cout << "Highest Temperature: " << maxTemp << " C" << endl;
    cout << "Lowest Temperature: " << minTemp << " C" << endl;
    cout << "Hot day: " << hotCount << endl;
    cout << "Hottest day: Day " << hottestDay << endl;

    return 0;
}
