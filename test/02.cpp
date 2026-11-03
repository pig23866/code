/**
 * C++ 模擬考題庫 - 第二題：校園販賣機結帳系統
 * 
 * 【功能與流程說明】
 * 1. 初始化總金額 amount 及各商品數量 (waterCount, teaCount, coffeeCount)，並在迴圈外顯示一次商品選單：
 *    (1) Water: 20元、(2) Tea: 30元、(3) Coffee: 45元、(0) Checkout。
 * 2. 使用 do ... while (choice != 0) 重複購物：
 *    - 內層 while (true) 驗證輸入編號必須為 0~3 的整數（遇 EOF 直接結束；格式錯誤則清除重問）。
 *    - 選擇 1~3 時分別累加對應商品的購買數量與總金額。
 *    - 選擇 0 時進入結帳分支，先輸出結帳明細與總計，再結束外層迴圈。
 * 3. 結帳明細使用三個獨立的 if（不可改為 else if），以便列出所有購買過的商品數量與「數量 × 單價」小計；
 *    若三種商品數量皆為 0，則顯示「尚未購買任何商品」。
 * 
 * 【測試重點】
 * - 測試輸入 1、2、3、1、0：應得水 2 瓶 (40元)、茶 1 瓶 (30元)、咖啡 1 杯 (45元)，總計 115 元。
 * - 測試文字、-1、4 等錯誤輸入：確認會提示錯誤且不會增加金額。
 */

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    // 1. 初始化變數：choice 初始值 -1 不是商品編號，進入判斷前會先讀取合法選項
    int choice = -1;
    int amount = 0;
    int waterCount = 0, teaCount = 0, coffeeCount = 0;

    // 2. 顯示商品選單（位於 do ... while 外，只顯示一次）
    cout << "\n====選單====\n";
    cout << "(1) Water: 20元\n";
    cout << "(2) Tea:30元\n";
    cout << "(3) Coffee: 45元\n";
    cout << "(0) Checkout\n";

    // 3. 使用 do ... while 重複購物，選擇 0 時先輸出結帳資料再結束
    do
    {
        // 4. 驗證輸入編號，直到取得有效的編號 (0~3)
        while (true)
        {
            cout << "請輸入選單編號(0~3):";
            if (!(cin >> choice))
            {
                // 若輸入結束 (EOF) 或嚴重讀取錯誤，直接結束程式，不輸出結帳明細
                if (cin.eof() || cin.bad())
                {
                    return 0;
                }
                else
                {
                    cout << "錯誤:請輸入整數!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            else if (choice < 0 || choice > 3)
            {
                cout << "錯誤:編號必須介於0~3, 請重新輸入!\n";
            }
            else
            {
                break; // 只離開內層驗證迴圈，不離開外層購物迴圈
            }
        }

        // 5. 依商品編號更新數量與金額（if ... else if ... else 四選一）
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
        else // choice == 0, 結帳（前三個分支已處理 1、2、3，此處必為 0）
        {
            cout << "\n====Check out====\n";
            cout << "購買商品明細: \n";

            // 6. 判斷是否尚未購買任何商品
            if (waterCount == 0 && teaCount == 0 && coffeeCount == 0)
            {
                cout << "尚未購買任何商品\n";
            }
            else
            {
                // 7. 三個獨立的 if，才能列出所有買過的商品（不能改成 else if）
                if (waterCount > 0)
                {
                    cout << "水: " << waterCount << "瓶,小計:"
                         << waterCount * 20 << "元\n";
                }
                if (teaCount > 0)
                {
                    cout << "茶: " << teaCount << "瓶,小計:"
                         << teaCount * 30 << "元\n";
                }
                if (coffeeCount > 0)
                {
                    cout << "咖啡: " << coffeeCount << "杯,小計:"
                         << coffeeCount * 45 << "元\n";
                }
            }

            // 顯示總金額（應等於 waterCount * 20 + teaCount * 30 + coffeeCount * 45）
            cout << "總計:" << amount << "元\n";
        }
    } while (choice != 0);

    return 0;
}
