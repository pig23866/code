#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;
int main() {
    // 設定為UTF-8編碼
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // 陣列宣告：儲存星期一至星期日（共 7 天）的銷售量
    int sales[7];

    // 星期名稱陣列，方便輸出與對應
    string dayNames[7] = {"星期一", "星期二", "星期三", "星期四", "星期五", "星期六", "星期日"};

    cout << "=== 請輸入一週咖啡銷售量 ===" << endl;
    // 使用 for 輸入星期一到星期日共 7 天的銷售量
    for (int i = 0; i < 7; i++) {
        cout << "請輸入" << dayNames[i] << "銷售量 : ";
        cin >> sales[i];

        // 若輸入數量小於 0，利用 if 顯示錯誤訊息並要求重新輸入
        if (sales[i] < 0) {
            cout << "【錯誤】銷售量不可小於 0，請重新輸入！" << endl;
            i--; // 計數器倒退，重新輸入該天
        }
    }
    
    int choice = -1;
    // 使用 while 重複執行主選單，直到選擇 0 離開
    while (choice != 0) {
        cout << "1. Water 20" << endl;
        cout << "2. Tea 30 " << endl;
        cout << "3. Coffee 45" << endl;
        cout << "0. 離開" << endl;
        cout << "請選擇：";
        cin >> choice;

        // 使用 switch 進行功能選擇
        switch (choice) {
            case 1: {

            }

            case 2: {

            }

            case 3: {
                // 功能 3：使用 for + if 找出最大銷售量，並顯示對應星期
                int maxSales = sales[0];
                int bestDayIndex = 0;

                for (int i = 1; i < 7; i++) {
                    if (sales[i] > maxSales) {
                        maxSales = sales[i];
                        bestDayIndex = i;
                    }
                }

                cout << "\n--- 銷售最好的一天 ---" << endl;
                cout << "最佳銷售日 : " << dayNames[bestDayIndex] << endl;
                cout << "銷售量 : " << maxSales << " 杯" << endl;
                break;
            }

            case 4: {
                // 功能 4：先計算平均，再使用 if 找出低於平均的日期與銷售量
                int total = 0;
                for (int i = 0; i < 7; i++) {
                    total += sales[i];
                }
                double average = static_cast<double>(total) / 7.0;

                cout << fixed << setprecision(2);
                cout << "\n--- 銷售低於平均 (" << average << " 杯) 的日期 ---" << endl;
                bool found = false;
                for (int i = 0; i < 7; i++) {
                    if (sales[i] < average) {
                        cout << dayNames[i] << " : " << sales[i] << " 杯" << endl;
                        found = true;
                    }
                }
                if (!found) {
                    cout << "無任何日期銷售量低於平均。" << endl;
                }
                break;
            }

            case 5: {
                // 功能 5：查詢指定日期銷售量 (輸入 1~7，可使用 switch 判斷星期)
                int dayChoice;
                cout << "\n請輸入要查詢的星期 (1 代表星期一，...，7 代表星期日)：";
                cin >> dayChoice;

                switch (dayChoice) {
                    case 1:
                        cout << "星期一的銷售量為 : " << sales[0] << " 杯" << endl;
                        break;
                    case 2:
                        cout << "星期二的銷售量為 : " << sales[1] << " 杯" << endl;
                        break;
                    case 3:
                        cout << "星期三的銷售量為 : " << sales[2] << " 杯" << endl;
                        break;
                    case 4:
                        cout << "星期四的銷售量為 : " << sales[3] << " 杯" << endl;
                        break;
                    case 5:
                        cout << "星期五的銷售量為 : " << sales[4] << " 杯" << endl;
                        break;
                    case 6:
                        cout << "星期六的銷售量為 : " << sales[5] << " 杯" << endl;
                        break;
                    case 7:
                        cout << "星期日的銷售量為 : " << sales[6] << " 杯" << endl;
                        break;
                    default:
                        cout << "【錯誤】無效的星期代號，請輸入 1 到 7 之間的數字！" << endl;
                        break;
                }
                break;
            }

            case 6: {
                // 延伸挑戰 (加分)：計算本週營業額（每杯咖啡 60 元）
                int total = 0;
                for (int i = 0; i < 7; i++) {
                    total += sales[i];
                }
                int revenue = total * 60;

                cout << "\n--- 本週營業額計算 ---" << endl;
                cout << "本週總銷售杯數 : " << total << " 杯" << endl;
                cout << "單杯售價 : 60 元" << endl;
                cout << "本週總營業額 : " << revenue << " 元" << endl;
                break;
            }

            case 0:
                cout << "\n感謝使用，系統已離開！" << endl;
                break;

            default:
                cout << "\n【錯誤】無效的選項，請重新輸入 0~6 的數字！" << endl;
                break;
        }
    }

    return 0;
}
