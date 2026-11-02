#include <iostream>
#include <limits>

using namespace std;

int main()
{

    int StudentCount = 0;
    int i;
    const int MAX_STUDENTS = 30;
    int score[MAX_STUDENTS] = {0};
    int pass = 0, fail = 0;

    while (true)
    {
        cout << "請輸入學生總人數(0~30):";
        if (!(cin >> StudentCount))
        {
            cout << "錯誤:請輸入整數!\n";

            if (cin.eof() || cin.bad())
                return 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (StudentCount < 0 || StudentCount > 30)
        {
            cout << "錯誤:學生人數必須介於0~30, 請重新輸入!\n";
        }
        else
        {
            break;
        }
    }

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
                break;
            }
        }

        if (score[i - 1] >= 60)
            pass++;
        else
            fail++;
    }

    cout << "學生總人數:" << StudentCount << "\n";

    for (i = 1; i <= StudentCount; i++)
    {
        cout << "學生" << i << "成績:" << score[i - 1] << "\n";
    }

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

    cout << "及格人數:" << pass << "\n";
    cout << "不及格人數:" << fail << "\n";

    return 0;
}
