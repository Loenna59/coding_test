#include <iostream>
#include <string>
#include <set>

int main() {
    int n;
    std::string input;

    std::cin >> n >> input;

    std::set<char> letters(input.begin(), input.end());

    std::string lower = "roygbiv";
    std::string upper = "ROYGBIV";

    bool canLower = true;
    bool canUpper = true;

    for (char c : lower) {
        if (letters.find(c) == letters.end()) {
            canLower = false;
            break;
        }
    }

    for (char c : upper) {
        if (letters.find(c) == letters.end()) {
            canUpper = false;
            break;
        }
    }

    if (canLower && canUpper) {
        std::cout << "YeS\n";
    } else if (canUpper) {
        std::cout << "YES\n";
    } else if (canLower) {
        std::cout << "yes\n";
    } else {
        std::cout << "NO!\n";
    }

    return 0;
}