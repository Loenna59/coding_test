#include <iostream>

using namespace std;

int main()
{
    int r = 31;
    long M = 1234567891;
    long long l;
    cin >> l;
    
    char* str = new char[l];

    cin >> str;

    long long hash = 0;
    long long r_pow = 1;

    for (int i = 0; i < l; i++)
    {
        int n = str[i] - 96;
        hash += n * r_pow ;
        hash %= M;
        r_pow *= r;
        r_pow %= M;
    }

    cout << hash;

    delete str;

    return 0;
}