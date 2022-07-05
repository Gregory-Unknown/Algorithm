#include <iostream>
#include <vector>

std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> res;
    for (char ch : digits) {
        std::string s = m[ch - '0'];
        if (!res.size()) {
            for (char i : s) {
                std::string tmp = " ";
                tmp[0] = i;
                res.push_back(tmp);
            }
        } else {
            std::vector<std::string> newRes;
            for (std::string old : res) {
                for (char i : s) {
                    newRes.push_back(old + i);
                }
            }
            res = newRes;
        }
    }
    return res;
}

int main() {
    std::vector<std::string> res;
    res = letterCombinations("2345");
    for (auto i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}