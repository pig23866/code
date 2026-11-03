#include <iostream>
using namespace std;

int main() {
    int Temperature[7];

    cout << "Input Temperature" << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Day " << (i + 1) << " Temperature: ";
        cin >> Temperature[i];
    }

    int sum = 0;
    for (int i = 0; i < 7; i++) {
        sum += Temperature[i];
    }
    double average = static_cast<double>(sum) / 7;

    int s = 0;
    for (int i = 0; i < 7; i++) {
        if (Temperature[i] >= 35) {
            s++;
        }
    }

    int maxScore = Temperature[0];
    int minScore = Temperature[0];
    int t = 1; // 記錄最熱的天數（預設為第 1 天）

    for (int i = 0; i < 7; i++) {
        if (Temperature[i] > maxScore) {
            maxScore = Temperature[i];
            t = i + 1; // 轉為 1-based 的第幾天 (Day 1 ~ Day 7)
        }
        if (Temperature[i] < minScore) {
            minScore = Temperature[i];
        }
    }

    cout << "Average Temperature: " << average << " C" << endl;
    cout << "Highest Temperature: " << maxScore << " C" << endl;
    cout << "Lowest Temperature: " << minScore << " C" << endl;
    cout << "Hot day: " << s << endl;
    cout << "Hottest day: Day " << t << endl;

    return 0;
}
