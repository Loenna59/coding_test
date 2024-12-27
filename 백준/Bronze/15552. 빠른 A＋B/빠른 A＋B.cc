#include <cstdio>

int main()
{
    long n;
    scanf("%ld", &n);

    for (long i = 0; i < n; i++)
    {
        long x, y;
        scanf("%ld %ld", &x, &y);
        printf("%ld\n", x + y);
    }

    return 0;
}