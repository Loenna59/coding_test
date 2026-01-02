#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1;
    string str2;

    cin >> str1 >> str2;

    int num1 = stoi(str1);

    cout << num1 * (str2[2] - '0') << "\n";
    cout << num1 * (str2[1] - '0') << "\n";
    cout << num1 * (str2[0] - '0') << "\n";
    cout << num1 * stoi(str2);

    return 0;
}