#include <iostream>
#include <queue>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    cin >> n;

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        q.pop();

        int front = q.front();
        q.pop();
        q.push(front);
    }

    cout << q.front();

    return 0;
}