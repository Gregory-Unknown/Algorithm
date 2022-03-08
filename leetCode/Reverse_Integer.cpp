#include <iostream>
#include <stack>
#include <climits>

int reverse(int x) {
    std::stack<int>st;
    for (; x != 0; x /= 10) {
        st.push(x % 10);
    }
    long res = 0;
    for (long i = 1; !st.empty(); i *= 10)
    {
        res += st.top() * i;
        st.pop();
    }
    if (res > INT_MAX || res < INT_MIN) return (0);
    return (res);
}

int main()
{
    int num = 12334567890987654321;

    std::cout << reverse(num) << std::endl;
}