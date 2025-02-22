#include <cstdio>

int main()
{    
    long long m;

    scanf("%lld", &m);
    
    int s = 0;
    bool checked = false;

    for (long long i = 0; i < m; i++)
    {
        char macro[7];
        scanf("%s", macro);

        if (macro[0] == 'a' && macro[1] == 'l')
        {
            s = (1 << 21) - 1;
            continue;
        }

        if (macro[0] == 'e')
        {
            s = 0;
            continue;
        }

        int num;
        scanf("%d", &num);

        int element = (1 << num);

        if (macro[0] == 'a')
        {
            if (s & element)
            {
                continue;
            }

            s |= element;
        }

        if (macro[0] == 'r')
        {
            if (s & element)
            {
                s &= ~element;
            }
        }

        if (macro[0] == 'c')
        {
            if (checked)
            {
                printf("\n");
            }
            else
            {
                checked = true;
            }

            printf("%d", (s & element)? 1 : 0);
        }

        if (macro[0] == 't')
        {
            s ^= element;
        }
    }

    return 0;
}