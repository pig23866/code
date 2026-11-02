#include <iostream>

using namespace std;

int calculateTotal(int stock[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += stock[i];
    }
    return total;
}

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
