#include <iostream>

using namespace std;

int main()
{
    string star = "*";
    int num;

    cin >> num;

    for (int j = 0; j < num; j++)
    {
        for (int i = 0; i < num; i++)
        {
            if (i >= j)
            {
                cout << star;
                continue;
            }
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}