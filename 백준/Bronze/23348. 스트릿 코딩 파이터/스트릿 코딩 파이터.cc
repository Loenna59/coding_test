#include <iostream>

int main()
{
    int a;
    int b;
    int c;

    std::cin >> a >> b >> c;

    int n;

    std::cin >> n;

    int greatest = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int x = 0; x < 3; x++)
        {
            int input_a;
            int input_b;
            int input_c;

            std::cin >> input_a >> input_b >> input_c;

            sum += input_a * a + input_b * b + input_c * c;
        }

        if (greatest < sum)
        {
            greatest = sum;
        }
    }

    std::cout << greatest;

    return 0;
}