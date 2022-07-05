#include <iostream>

bool isPalindrome(int x) {
    bool res = false;
    int reverse = 0;
    if (x < 0) return (false);
    for (int i = x; i != 0; i /= 10)
        reverse = (10 * reverse) + (i % 10);
    if (reverse == x) res = true;
    return (res);
}

int main()
{
    std::cout << isPalindrome(-101) << std::endl;
}