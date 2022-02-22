#include <iostream>


std::string longestPalindrome(std::string s) {
    std::string res = "";
    int len = 0;

    for (int i = 0; i < s.size(); ++i) {
        int l = i, r = i;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if ((r - l + 1) > len) {
                len = r - l + 1;
                res = s.substr(l, len);
            }
            --l;
            ++r;
        }
        l = i;
        r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if ((r - l + 1) > len) {
                len = r - l + 1;
                res = s.substr(l, len);
            }
            --l;
            ++r;
        }
    }
    return (res);
}

int main()
{
    std::string s = "a";
    s = longestPalindrome(s);
    std::cout << "s    = " << s << std::endl;

}