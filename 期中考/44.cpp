/**
 * C++ 模擬考題庫_2 - 題目四：倉庫庫存管理與補貨系統（考試簡化版）
 * 
 * 【程式碼分段說明】
 * 1. 引入函式庫與命名空間：不使用 <limits> 與 <vector>，輸入錯誤時以 cin.ignore(1000, '\n'); 處理；
 *    採用「先定義四個功能函式、再撰寫 int main()」的順序。
 * 2. calculateTotal(int stock[], int n)   : 使用 for 迴圈逐項累加 stock[i]，計算所有商品總庫存量。
 * 3. countLowStock(int stock[], int n)    : 檢查每項商品，庫存 < 10 才將 count 加 1（剛好 10 件不算低庫存），回傳低庫存「種類數」。
 * 4. findLowestStock(int stock[], int n)  : 先將 stock[0] 設為 lowest，從 i = 1 (第二項) 開始比較更新，回傳最低庫存量。
 * 5. calculateRestock(int currentStock)   : 庫存 < 10 件時補足至 20 件（回傳 20 - currentStock），10 件以上不補貨（回傳 0）。
 * 6. 輸入並檢查商品種類數 n               : 以 while (true) 驗證整數且介於 1~30。
 * 7. 輸入每項商品的非負庫存量 stock[i]    : 陣列索引從 0 開始（提示顯示 i + 1），拒絕非整數與負數 (< 0)。
 * 8. 計算統計資料與總補貨量               : 呼叫統計函式，並逐項累加 calculateRestock(stock[i]) 至 totalRestock（要新增的件數）。
 * 9. 顯示補貨清單與結果                   : 若 totalRestock == 0 顯示 No Restock Required；否則僅列出補貨量 > 0 的商品明細，最後輸出總補貨量。
 * 
 * 【範例驗算】
 * 假設 4 項商品庫存依序為 5、10、0、22：
 * - 總庫存：5 + 10 + 0 + 22 = 37
 * - 低庫存商品種類：第 1 項(5) 與第 3 項(0)，共 2 種
 * - 最低庫存量：0 件
 * - 補貨清單：第 1 項補 15 件 (20-5)、第 3 項補 20 件 (20-0)；總補貨量：35 件
 */

#include <iostream>

using namespace std;

// 計算所有商品的總庫存量 caculate:計算
int calculateTotal(int stock[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += stock[i];
    }
    return total;
}

// 計算庫存小於 10 件的商品種類數
int countLowStock(int stock[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (stock[i] < 10)
        {
            count++;
        }
    }
    return count;
}

// 找出最低庫存量
int findLowestStock(int stock[], int n)
{
    int lowest = stock[0];
    for (int i = 1; i < n; i++)
    {
        if (stock[i] < lowest)
        {
            lowest = stock[i];
        }
    }
    return lowest;
}

// 庫存小於 10 件時補至 20 件,否則不補貨
int calculateRestock(int currentStock)
{
    if (currentStock < 10)
    {
        return 20 - currentStock;
    }
    return 0;
}

int main()
{
    int n;

    // 商品種類數必須介於 1~30
    while (true)
    {
        cout << "Enter number of products (1-30): ";
        if (!(cin >> n))
        {
            cout << "Please enter an integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (n < 1 || n > 30)
        {
            cout << "Number of products must be between 1 and 30.\n";
            continue;
        }
        break;
    }

    int stock[30];

    // 輸入每項商品的非負庫存量
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            cout << "Enter stock for product " << i + 1 << ": ";
            if (!(cin >> stock[i]))
            {
                cout << "Please enter an integer.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (stock[i] < 0)
            {
                cout << "Stock cannot be negative.\n";
                continue;
            }
            break;
        }
    }

    int totalStock = calculateTotal(stock, n);
    int lowStockCount = countLowStock(stock, n);
    int lowestStock = findLowestStock(stock, n);
    int totalRestock = 0;

    // 先計算總補貨量
    for (int i = 0; i < n; i++)
    {
        totalRestock += calculateRestock(stock[i]);
    }

    cout << "\nTotal stock: " << totalStock << endl;
    cout << "Low-stock product types: " << lowStockCount << endl;
    cout << "Lowest stock: " << lowestStock << endl;

    if (totalRestock == 0)
    {
        cout << "No Restock Required" << endl;
    }
    else
    {
        cout << "\nRestock list:" << endl;
        cout << "Product number | Current stock | Restock quantity" << endl;

        for (int i = 0; i < n; i++)
        {
            int restockAmount = calculateRestock(stock[i]);
            if (restockAmount > 0)
            {
                cout << i + 1 << " | "
                     << stock[i] << " | "
                     << restockAmount << endl;
            }
        }
    }

    cout << "Total restock quantity: " << totalRestock << endl;

    return 0;
}
