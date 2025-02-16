#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;

    cin >> n;

    if (n == 0)
    {
        cout << '0';
        return 0;
    }

    long long exclude = round(n * 0.15);

    vector<int> difficulties;

    for (long long i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        difficulties.push_back(input);
    }

    sort(difficulties.begin(), difficulties.end());

    if (exclude > 0)
    {
        difficulties.erase(difficulties.begin(), difficulties.begin() + exclude);
        difficulties.erase(difficulties.end() - exclude, difficulties.end());
    }

    double size = n - 2 * exclude;

    long long avg = round(reduce(difficulties.begin(), difficulties.end(), 0) / size);

    cout << avg;

    return 0;
}