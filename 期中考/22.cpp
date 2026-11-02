/**
 * C++ 模擬考題庫_2 - 題目二：存錢目標系統（考試簡化版）
 * 
 * 【題目敘述】
 * - 使用者輸入大於 0 的存錢目標，之後逐日輸入存款，直到累積金額達標。
 * - 使用 while 迴圈讀取每天的存款額，並累加有效存款。
 * - 當日存款須大於 0；不合法時輸出 Invalid Amount，重新輸入且不計入天數。
 * - 每次有效存款後輸出當前總額，達標後輸出天數與存款總額。
 * 
 * 【程式碼分段說明】
 * 1. 宣告變數：金額 (target, amount, total) 使用 double 可儲存小數；有效存款天數 (days) 使用 int。
 * 2. 讀取目標：以 while (true) 處理文字輸入失敗、零與負數 (target <= 0)，輸出 Invalid Target 並以 continue 重問；合法才 break。
 * 3. 持續讀取每日存款：以 while (total < target) 在未達標時持續讀入下一筆存款。
 * 4. 跳過無效金額：當讀取失敗或 amount <= 0 時，輸出 Invalid Amount 並以 continue 跳過本輪，不累加金額也不增加天數。
 * 5. 累加有效存款：執行 total += amount; 與 days++;，並顯示當前累計總額 Current total。
 * 6. 達標後輸出總結：累計金額 >= 目標後離開迴圈（最後一筆存款不截減，總額可能超過目標），輸出 Goal reached!、天數與總額。
 */

#include <iostream>

using namespace std;

int main()
{
    // 用double的原因:
    // 假如使用int宣告,今天差0.1元就能達成目標,他現在輸入0.5元了, 但還是偵測不到後方小數
    // 這時因為int只能偵測整數,一樣無法達到存款目標(target)
    double target = 0; // 存款目標
    double amount = 0; // 每次輸入的存款金額
    double total = 0;  // 目前累計的存款金額
    int days = 0;      // 存入有效存款的天數,用 int 宣告是因為根本不會有 0.1 天這種標示方式

    // 持續輸入,直到成功讀取大於 0 的目標
    while (true)
    {
        cout << "Enter saving target: ";
        if (!(cin >> target))
        {
            cout << "Invalid Target" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (target <= 0)
        {
            cout << "Invalid Target" << endl;
            continue;
        }
        break;
    }

    while (total < target) // 當 目前累計的存款金額(total) 小於 存款目標(target) ...
    {
        cout << "Enter daily deposit: "; // daily deposit 是每日存款的意思,當然也可以取自己聽得懂的
        if (!(cin >> amount))            // 如果讀取失敗,例如輸入英文字母
        {
            cout << "Invalid Amount" << endl;
            cin.clear();           // 先清除錯誤狀態
            cin.ignore(1000, '\n'); // 再丟棄該行剩餘內容,最多 1000 字元
            continue;              // 重新輸入,不累加金額,也不增加天數
        }

        if (amount <= 0) // 如果這時偵測到 存款金額(amount) 小於 或是 等於0
        {
            cout << "Invalid Amount" << endl;
            continue; // 輸入的存款金額(amount)無效,所以也不會增加天數,所以又要再跑回while頂端重問使用者問題
        }

        total += amount; // 當前累計的存款金額(total)加上新存款金額(amount) = 新累計的存款金額(total)
        days++;          // 系統偵測到該存款金額(amount)是有效的,存入有效存款的天數(days)再加一天

        cout << "Current total: " << total << endl;
    }

    cout << "Goal reached!" << endl;
    cout << "Days: " << days << endl;
    cout << "Total savings: " << total << endl;

    return 0;
}
