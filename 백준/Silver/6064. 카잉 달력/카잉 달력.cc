#include <iostream>
#include <vector>
#include <algorithm>


// 중국인의 나머지 정리 (Chinese Remainder Theorem, CRT)

// 서로 서로소(공약수가 1)인 여러 수들에 대해 각각 주어진 나머지를 만족하는 하나의 수를 찾는 방법

// 예를 들어, 다음 조건을 만족하는 수를 찾고 싶을 때:
//     x≡2(mod3)
//     x≡3(mod5)
//     x≡2(mod7)
// 이런 식으로 여러 "나머지 조건"을 동시에 만족하는 수 x를 찾는 것이 목표

// 모두 서로소 (즉, 공약수가 1이어야 함)
// 최종 해는 mod (m1×m2×⋯ )안에서 유일하게 존재

// 확장 유클리드 알고리즘: ax + by = gcd(a, b) 를 만족하는 (x, y) 반환
std::pair<long long, long long> extended_gcd(long long a, long long b)
{
    if (b == 0)
    {
        return {1, 0};
    }

    auto [x1, y1] = extended_gcd(b, a % b);

    return {y1, x1 - (a / b) * y1};
}

// 모듈러 역원 구하기 (a * x ≡ 1 mod m 인 x)
long long mod_inverse(long long a, long long m)
{
    auto [x, y] = extended_gcd(a, m);

    long long g = a * x + m * y; //gcd
    
    return g == 1? (x % m + m) % m : -1;
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {

        int m;
        int n;
        int x;
        int y;

        std::cin >> m >> n >> x >> y;

        long long M = 1LL * m * n;
        long long result = -1;

        // (x, y)는 1부터 시작하므로 나머지를 맞춰줌
        x--; 
        y--;

        // 두 방정식: 연도 ≡ x (mod m), 연도 ≡ y (mod n)
        for (long long k = x; k < M; k += m)
        {
            if (k % n == y)
            {
                result = k + 1; // 1-based로 복원
                break;
            }
        }

        if (i > 0)
        {
            std::cout << "\n";
        }

        std::cout << result;
    }

    return 0;
}