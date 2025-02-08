#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

// BFS를 이용해 한 개의 서브트리 크기를 계산하는 함수
int bfs(int start, vector<vector<int>>& t, vector<bool>& visited) 
{
    queue<int> q;
    
    q.push(start);
    
    visited[start] = true;
    
    int count = 1;

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();

        for (int neighbor : t[node]) 
        {
            if (!visited[neighbor]) 
            {
                visited[neighbor] = true;
                q.push(neighbor);
                count++;
            }
        }
    }

    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    vector<vector<int>> t(n + 1); // 1-based 인덱스 트리 저장

    // 트리 구축 (양방향 연결)
    for (int i = 0, count =  wires.size(); i < count; i++)
    {
        int x = wires[i][0];
        int y = wires[i][1];

        t[x].push_back(y);
        t[y].push_back(x);
    }

    // 간선 하나씩 제거해가며 최소 차이 찾기
    for (int i = 0, count = wires.size(); i < count; i++)
    {
        int x = wires[i][0];
        int y = wires[i][1];

        // 간선 제거
        t[x].erase(remove(t[x].begin(), t[x].end(), y), t[x].end());
        t[y].erase(remove(t[y].begin(), t[y].end(), x), t[y].end());

        // BFS 실행
        vector<bool> visited(n + 1, false);
        int subtreeSize = bfs(x, t, visited);
        int otherSize = n - subtreeSize;

        // 최소 차이 갱신
        answer = min(answer, abs(subtreeSize - otherSize));

        // 간선 복구
        t[x].push_back(y);
        t[y].push_back(x);
    }
    
    return answer;
}