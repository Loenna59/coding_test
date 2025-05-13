#include <iostream>
#include <vector>

const int dx[8] { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[8] { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    std::cin >> n;

    std::vector<std::vector<int>> map(n, std::vector<int>(n, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            char ch;
            std::cin >> ch;

            if (isdigit(ch))
            {
                map[i][j] = ch - '0';
            }
        }
    }

    std::vector<std::vector<char>> answers(n, std::vector<char>(n, '*'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            if (map[i][j] > 0)
            {
                continue;
            }

            int mine = 0;

            for (int d = 0; d < 8; d++)
            {
                int ndx = j + dx[d];
                int ndy = i + dy[d];

                
                if (ndx >= 0 && ndx < n && ndy >= 0 && ndy < n)
                {
                    mine += map[ndy][ndx];
                }
            }

            answers[i][j] = mine < 10? (mine + '0') : 'M';
        }
    }
    

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            std::cout << "\n";
        }

        for (int j = 0; j <n; j++)
        {
            std::cout << answers[i][j];
        }
    }

    return 0;
}