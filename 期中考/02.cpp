/**
 * 功能說明：飲品販賣機點餐與結帳系統
 * 
 * 題目需求與功能描述：
 * 1. 顯示商品選單：
 *    - (1) Water : 20元
 *    - (2) Tea   : 30元
 *    - (3) Coffee: 45元
 *    - (0) Checkout (結帳離開)
 * 2. 使用 do-while 迴圈讓使用者重複點餐，並對輸入編號進行整數及範圍防呆驗證 (0~3)。
 * 3. 根據使用者選擇累計各品項的購買數量與總金額。
 * 4. 輸入 0 時進行結帳，印出購買商品明細（列出有購買的品項、數量與小計），若無購買任何商品則顯示提示，最後顯示總計金額。
 */

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int choice = -1;                                        // 使用者選單輸入選項
    int amount = 0;                                         // 購買總金額累計
    int waterCount = 0, teaCount = 0, coffeeCount = 0;      // 各品項數量累計

    // 印出商品選單
    cout << "\n====選單====\n";
    cout << "(1) Water: 20元\n";
    cout << "(2) Tea: 30元\n";
    cout << "(3) Coffee: 45元\n";
    cout << "(0) Checkout\n";

    // 點餐主迴圈：持續讓使用者點餐，直到選擇 0 結帳
    do
    {
        // ------------------------------------------
        // 輸入防呆驗證：確保輸入為介於 0~3 的整數
        // ------------------------------------------
        while (true)
        {
            cout << "請輸入選單編號(0~3): ";
            if (!(cin >> choice))
            {
                if (cin.eof() || cin.bad())
                {
                    return 0; // 若輸入流中斷則安全結束
                }
                else
                {
                    cout << "錯誤:請輸入整數!\n";
                    cin.clear();                                         // 重置輸入流錯誤狀態
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空緩衝區
                }
            }
            else if (choice < 0 || choice > 3)
            {
                cout << "錯誤:編號必須介於0~3, 請重新輸入!\n";
            }
            else
            {
                break; // 輸入有效，跳出驗證迴圈
            }
        }

        // ------------------------------------------
        // 依照使用者輸入的編號累計商品與金額
        // ------------------------------------------
        if (choice == 1)
        {
            waterCount++;
            amount += 20;
            cout << "水:20元\n";
        }
        else if (choice == 2)
        {
            teaCount++;
            amount += 30;
            cout << "茶:30元\n";
        }
        else if (choice == 3)
        {
            coffeeCount++;
            amount += 45;
            cout << "咖啡:45元\n";
        }
        else // choice == 0，進行結帳作業
        {
            cout << "\n====Check out====\n";
            cout << "購買商品明細: \n";

            // 檢查是否有購買任何商品
            if (waterCount == 0 && teaCount == 0 && coffeeCount == 0)
            {
                cout << "尚未購買任何商品\n";
            }
            else
            {
                // 分別列印有購買之商品品項、數量與小計
                if (waterCount > 0)
                {
                    cout << "水: " << waterCount << "瓶, 小計: " << waterCount * 20 << "元\n";
                }
                if (teaCount > 0)
                {
                    cout << "茶: " << teaCount << "瓶, 小計: " << teaCount * 30 << "元\n";
                }
                if (coffeeCount > 0)
                {
                    cout << "咖啡: " << coffeeCount << "杯, 小計: " << coffeeCount * 45 << "元\n";
                }
            }

            // 顯示最終總計金額
            cout << "總計: " << amount << "元\n";
        }
    } while (choice != 0);

    return 0;
}
