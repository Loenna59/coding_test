#include <iostream>
#include <vector>

int parent[51];

int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if (a != b)
    {
        parent[b] = a;
    }
}

int main()
{
    int n;
    int m;
    
    std::cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    int t;
    std::cin >> t;

    std::vector<int> truth(t);
    
    for (int i = 0; i < t; ++i)
    {
        std::cin >> truth[i];
    }

    std::vector<std::vector<int>> parties(m);

    for (int i = 0; i < m; ++i)
    {
        int k;
        std::cin >> k;

        parties[i].resize(k);
        
        for (int j = 0; j < k; ++j)
        {
            std::cin >> parties[i][j];
            if (j > 0)
            {
                unite(parties[i][j - 1], parties[i][j]);
            }
        }
    }

    int count = 0;

    for (int i = 0; i < m; ++i)
    {
        bool canLie = true;

        for (int person : parties[i])
        {
            for (int truthPerson : truth)
            {
                if (find(person) == find(truthPerson))
                {
                    canLie = false;
                    break;
                }
            }

            if (!canLie)
            {
                break;
            }
        }

        if (canLie)
        {
            ++count;
        }
    }

    std::cout << count << "\n";

    return 0;
}