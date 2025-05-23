#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;

vector<int> graph[MAX];
int parent[MAX];
bool visited[MAX];

void dfs(int current)
{
    visited[current] = true;

    for (int next : graph[current])
    {
        if (!visited[next])
        {
            parent[next] = current;
            dfs(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int u;
        int v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    for (int i = 2; i <= n; ++i)
    {
        cout << parent[i] << '\n';
    }

    return 0;
}
