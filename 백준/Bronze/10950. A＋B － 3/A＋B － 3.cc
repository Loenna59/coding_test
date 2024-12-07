#include <iostream>

int main()
{
    int num;

    std::cin >> num;

    int (*intArray)[2] = new int[num][2];

    for (int i = 0; i < num; i++)
    {
        std::cin >> (intArray[i])[0] >> intArray[i][1];
    }
    
    for (int i = 0; i < num; i++)
    {
        std::cout << intArray[i][0] + intArray[i][1] << std::endl;
    }
    
    return 0;
}