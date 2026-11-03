#include <iostream>
using namespace std;
int main() {
    int Temperature[7];

    cout << "Imput Temperature" << endl;
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
    for (int i = 0; i < 7; i++) {
        if (Temperature[i] > maxScore) {
          maxScore = Temperature[i];
        }
        if (Temperature[i] < minScore) {
        minScore = Temperature[i];
        }
    }
    int t = 0;
    for (int i = 0; i < 7; i++) {
        if (Temperature[i] >= 35) {
          t = i;
        }
    break;
    }


    cout << "Average Temperature: " << average << " C" << endl;
    cout << "Heigest Temperature: " << maxScore << " C" << endl;
    cout << "Lowestest Temperature: " << minScore << " C" << endl;
    cout << "Hot day: " << s << endl;
    cout << "Hottest day: Day " << t << endl;

    return 0;
}