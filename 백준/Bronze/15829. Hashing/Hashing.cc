#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int l;
    cin >> l;
    
    char* str = new char[l];

    cin >> str;

    long long sum = 0;

    for (int i = 0; i < l; i++)
    {
        int n = str[i] - 96;
        sum += n * pow(31, i);
    }

    cout << sum;

    delete str;

    return 0;
}