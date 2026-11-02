/**
 * 功能說明：商品庫存管理與補貨清單試算系統
 * 
 * 題目需求與功能描述：
 * 1. 輸入商品種類數量 n (介於 1~30 之間)，並進行整數及範圍防呆驗證。
 * 2. 依序輸入每項商品的目前庫存量（數值必須 >= 0 非負整數）。
 * 3. 模組化統計函式：
 *    - calculateTotal()   : 計算所有商品的庫存總數量。
 *    - countLowStock()    : 統計庫存偏低 (< 10 件) 的商品種類數。
 *    - findLowestStock()  : 找出所有商品庫存中的最低庫存量。
 *    - calculateRestock() : 判斷單一商品補貨量：若庫存 < 10 件則補足至 20 件 (補貨量 = 20 - 庫存)，否則不需補貨 (補貨量 = 0)。
 * 4. 輸出分析報告：
 *    - Total stock (總庫存量)
 *    - Low-stock product types (低庫存商品種類數)
 *    - Lowest stock (最低庫存量)
 *    - 補貨明細表 (Restock list)：若需補貨則列出品項編號、目前庫存與應補數量；若不需補貨則顯示 "No Restock Required"。
 *    - Total restock quantity (總補貨數量)。
 */

#include <iostream>

using namespace std;

// ==========================================
// 函式實作 (Function Implementations)
// ==========================================

/**
 * 函式名稱：calculateTotal
 * 功能：計算所有商品庫存總量 (calculate: 計算)
 * 參數：stock[] - 庫存陣列；n - 商品種類數
 * 回傳值：庫存總件數
 */
int calculateTotal(int stock[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += stock[i];
    }
    return total;
}

/**
 * 函式名稱：countLowStock
 * 功能：計算庫存小於 10 件的商品種類數
 * 參數：stock[] - 庫存陣列；n - 商品種類數
 * 回傳值：偏低庫存的商品種類數量
 */
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

/**
 * 函式名稱：findLowestStock
 * 功能：在所有商品中搜尋並找出最低庫存量
 * 參數：stock[] - 庫存陣列；n - 商品種類數
 * 回傳值：最低庫存件數
 */
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

/**
 * 函式名稱：calculateRestock
 * 功能：補貨規則試算：當庫存小於 10 件時補至 20 件，否則不補貨
 * 參數：currentStock - 當前單一商品的庫存數量
 * 回傳值：該商品應補貨數量 (0 或 20 - currentStock)
 */
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
    int n; // 商品種類總數

    // ==========================================
    // 第一部分：輸入商品種類總數 (範圍 1~30)
    // ==========================================
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

    int stock[30]; // 儲存各項商品庫存數量的陣列

    // ==========================================
    // 第二部分：逐項輸入商品非負庫存量
    // ==========================================
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

    // ==========================================
    // 第三部分：呼叫統計函式進行運算
    // ==========================================
    int totalStock = calculateTotal(stock, n);
    int lowStockCount = countLowStock(stock, n);
    int lowestStock = findLowestStock(stock, n);
    int totalRestock = 0;

    // 先計算總補貨量
    for (int i = 0; i < n; i++)
    {
        totalRestock += calculateRestock(stock[i]);
    }

    // ==========================================
    // 第四部分：輸出統計結果與補貨明細清單
    // ==========================================
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
                cout << i + 1 << " | " << stock[i] << " | " << restockAmount << endl;
            }
        }
    }

    cout << "Total restock quantity: " << totalRestock << endl;

    return 0;
}
