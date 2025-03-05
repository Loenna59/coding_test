#include <cstdio>
#include <queue>

int main()
{    
    long n;
    scanf("%dl", &n);

    std::vector<long long> answers;

    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap;

    for (long i = 0; i < n; i++)
    {
        long long input;
        scanf("%lld", &input);

        if (input == 0)
        {
            if (minHeap.empty())
            {
                answers.push_back(0);
                continue;
            }

            answers.push_back(minHeap.top());
            minHeap.pop();
            continue;
        }

        minHeap.push(input);
    }

    for (int i = 0, count = answers.size(); i < count; i++)
    {
        if (i > 0)
        {
            printf("\n");
        }
        
        printf("%lld", answers[i]);
    }

    return 0;
}