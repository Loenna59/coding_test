#include <iostream>

int main()
{
    int n;
    int m;

    std::cin >> n >> m;

    int count = 0;

	for (int y = 0; y < m - 1; y++)
	{
		for (int x = 0; x < n; ++x)
		{
			if (x - 1 >= 0 && y + 1 <= m -1)
			{
				count++;
			}
			if (x + 1 <= n - 1  && y + 1 <= m -1)
			{
				count++;
			}
		}	
	}

    std::cout << count;

    return 0;
}