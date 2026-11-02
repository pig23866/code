#include <iostream>
using namespace std;
int main() {
    // 陣列宣告：儲存 10 位學生的成績
    int scores[10];

    cout << "=== 請輸入 10 位學生的成績 ===" << endl;
    // 使用 for 依序輸入 10 位學生的成績
    for (int i = 0; i < 10; i++) {
        cout << "請輸入學生 " << (i + 1) << " 的成績 (0~100): ";
        cin >> scores[i];

        // 使用 if 判斷為錯誤資料，並要求重新輸入
        if (scores[i] < 0 || scores[i] > 100) {
            cout << "【錯誤】成績必須介於 0 到 100 之間，請重新輸入！" << endl;
            i--; // 計數器退回一步，重新輸入該位學生
        }
    }

    int choice = -1;

    // 使用 while 讓選單持續執行，直到使用者選擇 0
    while (choice != 0) {
        cout << "\n===== 成績管理系統 =====" << endl;
        cout << "1. 顯示全部成績" << endl;
        cout << "2. 計算平均成績" << endl;
        cout << "3. 顯示最高分與最低分" << endl;
        cout << "4. 統計及格與不及格人數" << endl;
        cout << "5. 顯示成績等級" << endl;
        cout << "0. 離開" << endl;
        cout << "請選擇功能：";
        cin >> choice;

        // 使用 switch 判斷使用者選擇的功能
        switch (choice) {
            case 1: {
                // 功能 1：顯示全部成績
                cout << "\n--- 全部學生成績 ---" << endl;
                for (int i = 0; i < 10; i++) {
                    cout << "學生 " << (i + 1) << " : " << scores[i];
                    if (i < 9) {
                        cout << "、";
                    }
                }
                cout << endl;
                break;
            }

            case 2: {
                // 功能 2：計算平均成績
                int sum = 0;
                for (int i = 0; i < 10; i++) {
                    sum += scores[i];
                }
                double average = static_cast<double>(sum) / 10.0;
                cout << "\n--- 平均成績 ---" << endl;
                cout << "所有學生成績總和 : " << sum << endl;
                cout << fixed << setprecision(2);
                cout << "平均成績 : " << average << endl;
                break;
            }

            case 3: {
                // 功能 3：最高分與最低分（利用 for + if）
                int maxScore = scores[0];
                int minScore = scores[0];

                for (int i = 1; i < 10; i++) {
                    if (scores[i] > maxScore) {
                        maxScore = scores[i];
                    }
                    if (scores[i] < minScore) {
                        minScore = scores[i];
                    }
                }

                cout << "\n--- 最高分與最低分 ---" << endl;
                cout << "最高分 : " << maxScore << endl;
                cout << "最低分 : " << minScore << endl;
                break;
            }

            case 4: {
                // 功能 4：及格與不及格人數（60分以上為及格）
                int passCount = 0;
                int failCount = 0;

                for (int i = 0; i < 10; i++) {
                    if (scores[i] >= 60) {
                        passCount++;
                    } else {
                        failCount++;
                    }
                }

                cout << "\n--- 及格與不及格人數統計 ---" << endl;
                cout << "及格人數 (>= 60) : " << passCount << " 人" << endl;
                cout << "不及格人數 (< 60) : " << failCount << " 人" << endl;
                break;
            }

            case 5: {
                // 功能 5：顯示成績等級
                cout << "\n--- 每位學生等級 ---" << endl;
                for (int i = 0; i < 10; i++) {
                    char grade;
                    if (scores[i] >= 90) {
                        grade = 'A';
                    } else if (scores[i] >= 80) {
                        grade = 'B';
                    } else if (scores[i] >= 70) {
                        grade = 'C';
                    } else if (scores[i] >= 60) {
                        grade = 'D';
                    } else {
                        grade = 'F';
                    }
                    cout << "學生 " << (i + 1) << " : " << scores[i] << " 分 -> 等級 " << grade << endl;
                }
                break;
            }

            case 0:
                cout << "\n感謝使用，系統已離開！" << endl;
                break;

            default:
                cout << "\n【錯誤】無效的選項，請重新輸入 0~5 的數字！" << endl;
                break;
        }
    }

    return 0;
}