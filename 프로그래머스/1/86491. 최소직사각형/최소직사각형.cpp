#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int width = 0;
    int height = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        for (int j = 0; j < sizes[i].size(); j++)
        {
            if (sizes[i][j] > width)
            {
                width = sizes[i][j];
            }
        }
    }

    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] > sizes[i][1])
        {
            if (sizes[i][1] > height)
            {
                height = sizes[i][1];
            }
        }
        else
        {
            if (sizes[i][0] > height)
            {
                height = sizes[i][0];
            }
        }
    }
    
    answer = width * height;
    
    return answer;
}