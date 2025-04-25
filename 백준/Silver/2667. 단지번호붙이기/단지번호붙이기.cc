#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

std::vector<int> bfs(std::vector<std::vector<int>>& grid, int n)
{
    std::queue<std::pair<int, int>> q;
    std::vector<int> distances;
    std::vector<std::pair<int, int>> visited;

    int index = -1;

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            std::pair<int, int> pair = {x, y};
            
            if (std::find(visited.begin(), visited.end(), pair) == visited.end() && grid[y][x] == 1)
            {
                q.push(pair);
                visited.push_back(pair);
                distances.push_back(1);
                
                index++;

                while (!q.empty())
                {
                    int current_x = q.front().first;
                    int current_y = q.front().second;
                    
                    q.pop();
            
                    for (int i = 0; i < 4; i++)
                    {
                        int ndx = current_x + dx[i];
                        int ndy = current_y + dy[i];
                        
                        if (ndx >= 0 && ndy >= 0 && ndx < n && ndy < n && grid[ndy][ndx] == 1)
                        {
                            std::pair<int, int> next_pair = {ndx, ndy};

                            if (std::find(visited.begin(), visited.end(), next_pair) == visited.end())
                            {
                                q.push(next_pair);
                                visited.push_back(next_pair);
                                distances[index]++;
                            }
                        }
                    }
                }
            }
        }
    }

    return distances;
}

int main()
{
    int n;

    std::cin >> n;

    std::vector<std::vector<int>> grid(n);

    for (int i = 0; i < n; i++)
    {
        std::string line;
        std::cin >> line;

        for (auto& ch : line)
        {
            grid[i].push_back(ch - 48);
        }
    }

    std::vector<int> answers = bfs(grid, n);

    std::sort(answers.begin(), answers.end());

    std::cout << answers.size();

    for (int answer : answers)
    {
        std::cout << "\n" << answer;
    }

    return 0;
}