#include <cstdio>
#include <cstdlib>

int main()
{
    char hex[7];

    scanf("%s", &hex);

    int result = strtol(hex, NULL, 16);

    printf("%d", result);

    return 0;
}