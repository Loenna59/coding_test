#include <iostream>
#include <vector>

// 현재 n * n 영역이 모두 같은 색인지 확인
// 같다면 -> 해당 색의 색종이 수 증가 후 종료
// 같지 않다면 -> 4등분 후 다시 모두 같은 색인지 확인 (재귀)

void partition(const std::vector<std::vector<int>>& arr, int start_x, int start_y, int size, int& answer_w, int& answer_b)
{
    int start = arr[start_x][start_y];
    
    if (size > 1)
    {
        for (int i = start_x; i < start_x + size; i++) 
        {
            for (int j = start_y; j < start_y + size; j++) 
            {
                if (start != arr[i][j])
                {
                    int half_size = size / 2;

                    partition(arr, start_x, start_y, half_size, answer_w, answer_b);
                    partition(arr, start_x + half_size, start_y, half_size, answer_w, answer_b);
                    partition(arr, start_x, start_y + half_size, half_size, answer_w, answer_b);
                    partition(arr, start_x + half_size, start_y + half_size, half_size, answer_w, answer_b);
                
                    return;
                }
            }
        }
    }
    
    if (start == 0)
    {
        answer_w++;
    }
    else
    {
        answer_b++;
    }
}

int main()
{
    int answer_w = 0;
    int answer_b = 0;

    int n;

    std::cin >> n;

    std::vector<std::vector<int>> arr(n, std::vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> arr[i][j];
        }
    }

    partition(arr, 0, 0, n, answer_w, answer_b);

    std::cout << answer_w << "\n" << answer_b;

    return 0;
}