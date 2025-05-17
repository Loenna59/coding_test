#include <iostream>
#include <queue>
#include <string>
#include <vector>

int D(int n)
{
    return (2 * n) % 10000;
}

int S(int n)
{
    return n == 0 ? 9999 : n - 1;
}

int L(int n)
{
    return (n % 1000) * 10 + (n / 1000);
}

int R(int n)
{
    return (n % 10) * 1000 + (n / 10);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        int a;
        int b;

        std::cin >> a;
        std::cin >> b;

        std::vector<bool> visited(10000, false);
        std::vector<std::string> command(10000, "");

        std::queue<int> q;

        q.push(a);
        visited[a] = true;

        while (!q.empty())
        {
            int current;
            current = q.front();
            q.pop();

            if (current == b)
            {
                std::cout << command[b] << '\n';
                break;
            }

            int next;

            next = D(current);
            if (!visited[next])
            {
                visited[next] = true;
                command[next] = command[current] + 'D';
                q.push(next);
            }

            next = S(current);
            if (!visited[next])
            {
                visited[next] = true;
                command[next] = command[current] + 'S';
                q.push(next);
            }

            next = L(current);
            if (!visited[next])
            {
                visited[next] = true;
                command[next] = command[current] + 'L';
                q.push(next);
            }

            next = R(current);
            if (!visited[next])
            {
                visited[next] = true;
                command[next] = command[current] + 'R';
                q.push(next);
            }
        }
    }

    return 0;
}