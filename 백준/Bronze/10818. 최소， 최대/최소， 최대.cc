#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int min;
    int max;

    for (int i = 0; i < n; i++)
    {
        int elem;
        scanf("%d", &elem);

        if (i == 0)
        {
            min = elem;
            max = elem;
            continue;
        }

        if (elem < min)
        {
            min = elem;
        }

        if (elem > max)
        {
            max = elem;
        }
    }

    printf("%d %d", min, max);

    return 0;
}