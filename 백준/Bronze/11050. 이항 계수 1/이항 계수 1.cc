#include <iostream>
#include <cstdio>

int factorial(int n, int f)
{
    if (n <= 1)
    {
        if (f <= 1)
        {
            return 1;
        }
        
        return f;
    }

    return factorial(n - 1, f * n);
}

int main()
{
    //이항계수 = n!/((n-k)! * k!)

    int n;
    int k;

    scanf("%d %d", &n, &k);

    int divide = (factorial(n - k - 1, n - k) * factorial(k - 1, k));

    if (divide > 0)
    {
        printf("%d", factorial(n - 1, n) / divide);
    }
    else
    {
        printf("0");
    }

    return 0;
}
