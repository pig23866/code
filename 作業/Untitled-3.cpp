#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    // 設定為UTF-8編碼
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // 陣列宣告：20 個座位，初始值皆為 0 (0: 空位, 1: 已售出)
    int seats[20] = {0};

    int choice = -1;

    // 使用 while 讓系統持續執行
    while (choice != 0) {
        cout << "\n========== 電影院訂票系統 ==========" << endl;
        cout << "1. 查看座位" << endl;
        cout << "2. 購買電影票" << endl;
        cout << "3. 取消訂票" << endl;
        cout << "4. 查看剩餘座位數" << endl;
        cout << "5. 查看售票率" << endl;
        cout << "0. 離開系統" << endl;
        cout << "請選擇功能：";
        cin >> choice;

        // 防呆：若輸入非數字等錯誤
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "【錯誤】輸入格式錯誤，請輸入數字！" << endl;
            continue;
        }

        // 使用 switch 執行不同功能
        switch (choice) {
            case 1: {
                // 功能 1：查看座位
                cout << "\n--- 座位狀態表 ---" << endl;
                // 使用 for 逐一檢查 seats[i]，每 5 個換一行
                for (int i = 0; i < 20; i++) {
                    cout << setw(2) << setfill('0') << (i + 1) << "[" << (seats[i] == 0 ? 'O' : 'X') << "]";
                    if ((i + 1) % 5 == 0) {
                        cout << endl;
                    } else {
                        cout << " ";
                    }
                }
                cout << "\nO: 空位   X: 已售出" << endl;
                break;
            }

            case 2: {
                // 功能 2：購買電影票
                int seatNumber;
                cout << "\n請輸入座位號碼 (1~20)：";
                cin >> seatNumber;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cout << "【錯誤】輸入無效，請輸入數字！" << endl;
                    break;
                }

                // 先使用 if 判斷座位號碼是否合法
                if (seatNumber < 1 || seatNumber > 20) {
                    cout << "【錯誤】座位號碼超出範圍，請輸入 1~20！" << endl;
                } else if (seats[seatNumber - 1] == 0) {
                    // 若 seats[seat-1] == 0，將其設為 1，並顯示「訂票成功」
                    seats[seatNumber - 1] = 1;
                    cout << "訂票成功！座位 " << seatNumber << " 號已為您保留。" << endl;
                } else {
                    // 若該位置已為 1，顯示「此座位已售出」
                    cout << "此座位已售出！請選擇其他座位。" << endl;
                }
                break;
            }

            case 3: {
                // 功能 3：取消訂票
                int seatNumber;
                cout << "\n請輸入欲取消的座位號碼 (1~20)：";
                cin >> seatNumber;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cout << "【錯誤】輸入無效，請輸入數字！" << endl;
                    break;
                }

                // 判斷座位號碼是否合法
                if (seatNumber < 1 || seatNumber > 20) {
                    cout << "【錯誤】座位號碼超出範圍，請輸入 1~20！" << endl;
                } else if (seats[seatNumber - 1] == 1) {
                    // 若該座位為 1，將其改回 0
                    seats[seatNumber - 1] = 0;
                    cout << "已成功取消座位 " << seatNumber << " 號的訂票！" << endl;
                } else {
                    // 若本來就是 0，顯示「此座位目前沒有訂票」
                    cout << "此座位目前沒有訂票！" << endl;
                }
                break;
            }

            case 4: {
                // 功能 4：查看剩餘座位數
                // 使用 for 統計 seats[i] == 0 的數量
                int emptyCount = 0;
                for (int i = 0; i < 20; i++) {
                    if (seats[i] == 0) {
                        emptyCount++;
                    }
                }
                int soldCount = 20 - emptyCount;

                cout << "\n--- 座位統計 ---" << endl;
                cout << "總座位 : 20" << endl;
                cout << "已售出 : " << soldCount << endl;
                cout << "剩餘座位 : " << emptyCount << endl;
                break;
            }

            case 5: {
                // 功能 5：查看售票率
                // 售票率 = 已售出座位數 ÷ 20 × 100%
                int soldCount = 0;
                for (int i = 0; i < 20; i++) {
                    if (seats[i] == 1) {
                        soldCount++;
                    }
                }

                double rate = (static_cast<double>(soldCount) / 20.0) * 100.0;

                cout << fixed << setprecision(1);
                cout << "\n--- 售票率分析 ---" << endl;
                cout << "目前售票率 : " << rate << "%" << endl;

                // 根據售票率判斷顯示訊息
                if (rate == 100.0) {
                    cout << "本場次已售完" << endl;
                } else if (rate >= 80.0) {
                    cout << "剩餘座位不多" << endl;
                } else if (rate >= 50.0) {
                    cout << "座位即將售完" << endl;
                } else {
                    cout << "目前還有很多座位" << endl;
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
