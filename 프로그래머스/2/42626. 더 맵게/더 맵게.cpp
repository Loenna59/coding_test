#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> heap(scoville.begin(), scoville.end());

    while (!heap.empty())
    {
        int s1 = heap.top();
        heap.pop();

        if (heap.empty())
        {
            break;
        }

        int s2 = heap.top();
        heap.pop();

        if (s1 >= K && s2 >= K)
        {
            break;
        }

        int mixed = s1 + s2 * 2;

        if (heap.empty() && mixed < K)
        {
            return -1;
        }

        heap.push(mixed);

        answer++;
    }

    return answer;
}