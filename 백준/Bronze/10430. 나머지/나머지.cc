#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int A;
    int B;
    int C;

    std::cin >> A >> B >> C;

    std::cout << (A + B) % C << "\n";

    std::cout << ((A % C) + (B % C)) % C << "\n";

    std::cout << (A * B) % C << "\n";

    std::cout << ((A % C) * (B % C)) % C;

    return 0;
}
