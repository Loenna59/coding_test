#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2; j++)
        {
            if (j > i && j < (n * 2 - 1) - i)
            {
                cout << " ";
                continue;
            }
            
            cout << "*";
        }
        cout << "\n";
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n * 2; j++)
        {
            if (j > n - i - 1 && j < n + i)
            {
                cout << " ";
                continue;
            }
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}