#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int choice = -1;
    int amount = 0;
    int waterCount = 0, teaCount = 0, coffeeCount = 0;

    cout << "\n====選單====\n";
    cout << "(1) Water: 20元\n";
    cout << "(2) Tea: 30元\n";
    cout << "(3) Coffee: 45元\n";
    cout << "(0) Checkout\n";

    do
    {
        // 檢查輸入，直到取得有效的編號
        while (true)
        {
            cout << "請輸入選單編號(0~3): ";
            if (!(cin >> choice))
            {
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
                break;
            }
        }

        // 依選擇累計商品與金額
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
        else // choice == 0, 結帳
        {
            cout << "\n====Check out====\n";
            cout << "購買商品明細: \n";

            if (waterCount == 0 && teaCount == 0 && coffeeCount == 0)
            {
                cout << "尚未購買任何商品\n";
            }
            else
            {
                // 三個獨立的 if，列出所有購買過的商品
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

            cout << "總計: " << amount << "元\n";
        }
    } while (choice != 0);

    return 0;
}
