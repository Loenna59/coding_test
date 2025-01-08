#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

// 추가 설명
// 트럭은 1초에 다리 길이 1씩 전진한다.
// 트럭은 올라갈수 있으면 1초에 한 대씩 다리에 올라갈 수 있다

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int current_bridge_weight = 0;

    queue<int> truck_queue;
    queue<int> bridge_queue(deque<int>(bridge_length, 0));
    
    for (int truck_weight : truck_weights)
    {
        truck_queue.push(truck_weight);
    }

    while (current_bridge_weight > 0 || !truck_queue.empty())
    {
        int wait_truck = truck_queue.empty()? 0 : truck_queue.front();
        int pop_weight = bridge_queue.front();

        bridge_queue.pop();
        current_bridge_weight -= pop_weight;

        if (current_bridge_weight + wait_truck <= weight)
        {
            bridge_queue.push(wait_truck);
            current_bridge_weight += wait_truck;

            if (!truck_queue.empty())
            {
                truck_queue.pop();
            }
        }
        else
        {
            bridge_queue.push(0);
        }

        answer++;
    }
    
    return answer;
}