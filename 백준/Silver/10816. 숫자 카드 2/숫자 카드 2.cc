#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    long long m;

    vector<long long> keys;
    unordered_map<long long, long long> map;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        map[num] += 1;
    }

    cin >> m;

    for (long long i = 0; i < m; i++)
    {
        long long key;
        cin >> key;
        keys.push_back(key);
    }

    for (long long i = 0, count = keys.size(); i < count; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << map[keys[i]];
    }

    return 0;
}