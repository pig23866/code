/**
 * 功能說明：學生成績統計系統
 * 
 * 題目需求與功能描述：
 * 1. 輸入學生總人數（介於 0 到 30 人之間），並進行整數防呆驗證。
 * 2. 依序輸入每位學生的成績（介於 0 到 100 分之間），並進行數值與格式防呆驗證。
 * 3. 判斷各學生是否及格（60 分以上為 pass，否則為 fail），並統計及格與不及格總人數。
 * 4. 最後印出學生總人數、每位學生成績、個別及格狀態以及及格/不及格人數總結。
 */

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    const int MAX_STUDENTS = 30;     // 最多支援的學生人數上限
    int StudentCount = 0;            // 實際輸入的學生總人數
    int score[MAX_STUDENTS] = {0};   // 儲存每位學生成績的陣列
    int pass = 0, fail = 0;          // 及格與不及格人數累計計數器
    int i;

    // ==========================================
    // 第一部分：輸入學生總人數（包含防呆輸入驗證）
    // ==========================================
    while (true)
    {
        cout << "請輸入學生總人數(0~30): ";
        // 檢查是否成功輸入整數
        if (!(cin >> StudentCount))
        {
            cout << "錯誤:請輸入整數!\n";
            if (cin.eof() || cin.bad())
                return 0;
            cin.clear();                                         // 清除 cin 錯誤標誌
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空緩衝區殘餘字元
        }
        else if (StudentCount < 0 || StudentCount > 30) // 範圍檢查 (0~30)
        {
            cout << "錯誤:學生人數必須介於0~30, 請重新輸入!\n";
        }
        else
        {
            break; // 輸入正確，跳出輸入迴圈
        }
    }

    // ==========================================
    // 第二部分：依序輸入每位學生成績並統計及格狀態
    // ==========================================
    for (i = 1; i <= StudentCount; i++)
    {
        while (true)
        {
            cout << "請輸入學生" << i << "的成績(0~100): ";
            if (!(cin >> score[i - 1]))
            {
                cout << "錯誤:請輸入整數!\n";
                if (cin.eof() || cin.bad())
                    return 0;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (score[i - 1] < 0 || score[i - 1] > 100) // 範圍檢查 (0~100)
            {
                cout << "錯誤:成績必須介於0~100, 請重新輸入!\n";
            }
            else
            {
                break; // 輸入正確，結束該學生成績輸入
            }
        }

        // 統計及格與不及格人數（60分為及格門檻）
        if (score[i - 1] >= 60)
            pass++;
        else
            fail++;
    }

    // ==========================================
    // 第三部分：輸出統計結果與成績清單
    // ==========================================
    cout << "\n學生總人數:" << StudentCount << "\n";

    // 列印每位學生的成績
    for (i = 1; i <= StudentCount; i++)
    {
        cout << "學生" << i << "成績:" << score[i - 1] << "\n";
    }

    // 列印每位學生的及格狀態 (pass / fail)
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

    // 列印及格與不及格的總人數
    cout << "及格人數:" << pass << "\n";
    cout << "不及格人數:" << fail << "\n";

    return 0;
}
