/**
 * C++ 模擬考題庫_2 - 題目一：票價判別系統（考試簡化版）
 * 
 * 【考試版調整說明】
 * 因部分語法已被老師禁用，且考試時間有限，優先採用簡短、可執行的寫法：
 * 將 cin.ignore(numeric_limits<streamsize>::max(), '\n'); 改為 cin.ignore(1000, '\n');，並移除 #include <limits>。
 * 
 * 【程式碼分段說明】
 * 1. 引入函式庫與設定年齡變數：宣告 int age = 0; 儲存整數年齡。
 * 2. 持續輸入直到年齡符合要求：使用 while (true) 搭配 !(cin >> age) 檢查整數輸入，
 *    並檢查年齡是否介於 0~100 歲（|| 代表「或」），合格才以 break 離開迴圈。
 * 3. 依年齡選擇票種與票價（if / else if / else 四選一，&& 代表「且」）：
 *    - 0 ~ 5 歲   (age <= 5)              : Free Ticket   ($0)
 *    - 6 ~ 17 歲  (age >= 6 && age <= 17) : Child Ticket  ($150)
 *    - 18 ~ 64 歲 (age >= 18 && age <= 64): Adult Ticket  ($300)
 *    - 65 ~ 100 歲 (else，已排除 0~64 歲)  : Senior Ticket ($150)
 * 4. 輸出結果並以 return 0; 正常結束程式。
 */

// 更改了 cin.ignore 的冗長指令,以及將 include<limits> 進行了刪除
#include <iostream>

using namespace std;

int main()
{
    int age = 0;

    while (true) // true 永遠為真,迴圈永遠執行,所以只能靠 break 跳出對話
    {
        cout << "請輸入年齡:";
        // 運作邏輯: 如果下方的 if 或是 else if 這2個其中一個的錯誤處理區域,有偵測到錯誤時
        // 會跳出錯誤提示, 然後系統會再跳回上面這句cout程式碼, 再次詢問使用者相同的問題
        // 這時就不會繼續留在if 或是 else if 這2個錯誤處理區域裡面了

        if (!(cin >> age)) // 這句就已經開始輸入了,只是他是順便寫成if,去同時判斷錯誤
        {
            cout << "請輸入整數!\n"; // 跳出錯誤提示
            cin.clear();              // 重置錯誤,將失敗狀態歸零,可繼續使用cin功能
            cin.ignore(1000, '\n');   // 清除緩衝區的所有錯誤,上限是1000字元,偵測到換行就停止清除
        }
        else if (age < 0 || age > 100) // 把沒設定進去的錯誤條件寫完,一樣跳出錯誤提示並跳回 while頂端
        {
            cout << "錯誤:年齡必須介於0~100!\n"; // 跳出錯誤提示
        }
        else // else後面千萬不要再寫(條件)了,因為已經由 if 排除完畢了,只有 if 才需加(條件)
        {
            break; // 如果系統偵測到輸入合理, 就可以break跳出去這個對話了, 問答環節到此為止
        }
    }

    // 下面使用 if...else 語法進一步偵測使用者的輸入, 並輸出相應的回答給使用者看
    if (age <= 5)
    {
        cout << "====Cinema Ticket====\n";
        cout << "Ticket Type: Free Ticket\n";
        cout << "Ticket Price: $0\n";
    }
    else if (age >= 6 && age <= 17)
    {
        cout << "====Cinema Ticket====\n";
        cout << "Ticket Type: Child Ticket\n";
        cout << "Ticket Price: $150\n";
    }
    else if (age >= 18 && age <= 64)
    {
        cout << "====Cinema Ticket====\n";
        cout << "Ticket Type: Adult Ticket\n";
        cout << "Ticket Price: $300\n";
    }
    else
    {
        cout << "====Cinema Ticket====\n";
        cout << "Ticket Type: Senior Ticket\n";
        cout << "Ticket Price: $150\n";
    }

    return 0; // 千萬不要忘記寫了, 拜託
}
