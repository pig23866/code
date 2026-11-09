#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int n = 7;
    int Temperature[n];


    cout << "Input Temperature" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Day " << (i + 1) << " Temperature: ";
        cin >> Temperature[i];
    }

    int sum = 0;
    int hotCount = 0; 
    int maxTemp = Temperature[0];
    int minTemp = Temperature[0];
    int hottestDay = 1; 

    for (int i = 0; i < n; i++) {
        sum += Temperature[i];

        if (Temperature[i] >= 35) {
            hotCount++;
        }
        if (Temperature[i] > maxTemp) {
            maxTemp = Temperature[i];
            hottestDay = i + 1;           
        }

        if (Temperature[i] < minTemp) {
            minTemp = Temperature[i];
        }
    }

    double average = static_cast<double>(sum) / n;

    cout << ""<< endl;
    cout << fixed << setprecision(2);
    cout << "Average Temperature: " << average << " C" << endl;
    cout << "Highest Temperature: " << maxTemp << " C" << endl;
    cout << "Lowest Temperature: " << minTemp << " C" << endl;
    cout << "Hot days: " << hotCount << endl;
    cout << "Hottest day: Day " << hottestDay << endl;

    return 0;
}
