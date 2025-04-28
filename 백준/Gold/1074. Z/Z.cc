#include <iostream>

void recursion(int x, int y, int r, int c, int size, int& result)
{
    if (size == 1)
    {
        return;
    }

    int half = size / 2;

    if (r < x + half && c < y + half)
    {
        recursion(x, y, r, c, half, result); //  좌상단
    }
    else if (r < x + half && c >= y + half)
    {
        result += half * half; // 우상단
        recursion(x, y + half, r, c, half, result);
    }
    else if (r >= x + half && c < y + half)
    {
        result += 2 * half * half; // 좌하단
        recursion(x + half, y, r, c, half, result);
    }
    else
    {
        result += 3 * half * half; // 우하단
        recursion(x + half, y + half, r, c, half, result);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int r;
    int c;
    
    std::cin >> n >> r >> c;

    int result = 0;

    recursion(0, 0, r, c, 1 << n, result); // 1 << n == 2^n

    std::cout << result; 

    return 0;
}