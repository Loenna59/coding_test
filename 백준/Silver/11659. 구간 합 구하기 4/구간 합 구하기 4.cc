#include <cstdio>
#include <vector>

int main()
{
    int m;
    int n;

    scanf("%d %d", &n, &m);

    std::vector<long> sums(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int input;
        scanf("%d", &input);

        sums[i] = input + sums[i - 1];
    }

    std::vector<long> answers(m);

    for (int i = 0; i < m; i++)
    {
        int start;
        int end;
        scanf("%d %d", &start, &end);

        answers[i] = sums[end] - sums[start - 1];
    }

    for (int i = 0; i < m; i++)
    {
        if (i > 0)
        {
            printf("\n");
        }

        printf("%ld", answers[i]);
    }

    return 0;
}