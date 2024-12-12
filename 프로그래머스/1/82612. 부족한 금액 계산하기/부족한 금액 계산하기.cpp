using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;

    long long total_price = count * (long long)price * (count + 1) / 2;

    answer = total_price > money? total_price - money : 0;

    return answer;
}