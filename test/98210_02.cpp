#include <iostream>

using namespace std;

int main()
{
    // 1. 程式起始樓層 = 1
    int currentFloor = 1;
    int targetFloor = 0;

    // 重複直到到達第一層
    while (true)
    {
        cout << "Enter target:";

        // 4. 若輸入非整數或不在 1~10 之間，顯示 Invalid Floor
        if (!(cin >> targetFloor))
        {
            if (cin.eof() || cin.bad())
            {
                return 0;
            }
            cout << "Invalid Floor" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (targetFloor < 1 || targetFloor > 10)
        {
            cout << "Invalid Floor" << endl;
            continue;
        }

        // 5. 若目標樓層為當前樓層（例如起始就在第 1 層且輸入 1），直接顯示抵達訊息
        if (targetFloor == currentFloor)
        {
            cout << "Arrived at Floor " << currentFloor << endl;
        }
        else
        {
            // 2. 用 while 模擬樓層移動：目標較高則每次加一；目標較低則每次減一
            // 3. 每移動一層都要顯示 Moving to X
            while (currentFloor != targetFloor)
            {
                if (targetFloor > currentFloor)
                {
                    currentFloor++;
                }
                else
                {
                    currentFloor--;
                }
                cout << "Moving to " << currentFloor << endl;
            }

            // 3. 抵達後顯示 Arrived at Floor X
            cout << "Arrived at Floor " << currentFloor << endl;
        }

        // 到達第一層時結束重複
        if (currentFloor == 1)
        {
            break;
        }
    }

    return 0;
}
