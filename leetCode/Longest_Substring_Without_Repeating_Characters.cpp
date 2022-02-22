#include <iostream>
#include <set>


int lengthOfLongestSubstring(std::string s) {
    int count = 0;
    std::set<char>res;
    int j = 0;
    for (int i = 0; i < s.size();) {
        int flag = res.size();
        res.insert(s[i]);
        if (flag == res.size()) {
            res.clear();
            ++j;
            i = j;
        }
        else {
            if (count < res.size()) {
                count = res.size();
            }
            ++i;
        }
        
    }
    if (count < res.size())
        count = res.size();
    return (count);
}

int main()
{
    std::string s = "abcabcbb";
    int res = lengthOfLongestSubstring(s);
    std::cout << "res : "  << res << std::endl;
}