/**
 * C++ 模擬考題庫 - 第一題：學生考試成績判定系統
 * 
 * 【功能與流程說明】
 * 1. 建立容量固定為 30 的成績陣列 score[MAX_STUDENTS]，並初始化為 0。
 * 2. 讀取並驗證學生總人數（合法範圍：0~30 人，本題允許 0 人）。
 *    - 若讀取非整數失敗：遇 EOF 或嚴重錯誤直接結束；一般格式錯誤則以 cin.clear() 與 cin.ignore() 清除。
 * 3. 逐一讀取每位學生的成績（合法範圍：0~100 分），學生 i 的成績存放於 score[i - 1]。
 * 4. 每筆合法成績輸入後立即統計一次及格（>= 60 分，pass++）或不及格（< 60 分，fail++）。
 * 5. 依序顯示學生總人數、各學生成績、各學生及格判定（pass / fail）以及及格與不及格總人數。
 * 
 * 【測試重點】
 * - 邊界測試：59 分 (fail)、60 分 (pass)、61 分 (pass)，應得及格 2 人、不及格 1 人。
 * - 若輸入 0 人，成績迴圈不執行，及格與不及格人數皆為 0。
 */

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    // 1. 宣告學生人數、成績陣列及統計變數
    // 陣列容量固定為 30 (合法索引 0~29)，{0} 將全部元素初始化為 0，只處理實際輸入的前 StudentCount 位學生
    int StudentCount = 0;
    int i;
    const int MAX_STUDENTS = 30;
    int score[MAX_STUDENTS] = {0};
    int pass = 0, fail = 0;

    // 2. 驗證學生人數 (持續要求輸入，直到取得 0~30 的合法整數)
    while (true)
    {
        cout << "請輸入學生總人數(0~30):";
        if (!(cin >> StudentCount))
        {
            cout << "錯誤:請輸入整數!\n";
            // 遇到輸入結束 (EOF) 或嚴重讀取錯誤時直接結束程式，避免無限重試
            if (cin.eof() || cin.bad())
                return 0;
            cin.clear();                                         // 清除錯誤狀態
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 丟棄該行剩餘內容
        }
        else if (StudentCount < 0 || StudentCount > 30)
        {
            cout << "錯誤:學生人數必須介於0~30, 請重新輸入!\n";
        }
        else
        {
            break; // 成功讀取且範圍合法，離開驗證迴圈
        }
    }

    // 3. 逐一讀取成績並統計及格與不及格人數
    // 陣列索引從 0 開始，學生 i 的成績存放於 score[i - 1]（例如學生 1 使用 score[0]）
    for (i = 1; i <= StudentCount; i++)
    {
        while (true)
        {
            cout << "請輸入學生" << i << "的成績(0~100)";
            if (!(cin >> score[i - 1]))
            {
                cout << "錯誤:請輸入整數!\n";
                if (cin.eof() || cin.bad())
                    return 0;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (score[i - 1] < 0 || score[i - 1] > 100)
            {
                cout << "錯誤:成績必須介於0~100, 請重新輸入!\n";
            }
            else
            {
                break; // 成績合法，離開內層驗證迴圈
            }
        }

        // 4. 統計及格與不及格人數：60 分以上列為及格，每筆合法成績只統計一次
        if (score[i - 1] >= 60)
            pass++;
        else
            fail++;
    }

    // 5. 顯示各學生的成績與判定結果
    cout << "學生總人數:" << StudentCount << "\n";

    // 第一個輸出迴圈：列出每位學生的成績
    for (i = 1; i <= StudentCount; i++)
    {
        cout << "學生" << i << "成績:" << score[i - 1] << "\n";
    }

    // 第二個輸出迴圈：顯示 pass 或 fail（與統計使用相同條件 >= 60）
    for (i = 1; i <= StudentCount; i++)
    {
        if (score[i - 1] >= 60)
        {
            cout << "學生" << i << ":pass\n";
        }
        else
        {
            cout << "學生" << i << ":fail\n";
        }
    }

    // 輸出及格與不及格總人數（pass + fail == StudentCount）
    cout << "及格人數:" << pass << "\n";
    cout << "不及格人數:" << fail << "\n";

    return 0;
}
