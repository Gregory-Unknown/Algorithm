#include <iostream>
#include <vector>

void func(std::vector<std::string>& res, int n, int l, int r, std::string s) {
    if (s.size() == n * 2) {
        res.push_back(s);
        return ;
    }
    if (l < n) func(res, n, l + 1, r, s + "(");
    if (r < l) func(res, n, l, r + 1, s + ")" );
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    func(res, n, 0, 0, "");
    return res;
}

int main() {
    std::vector<std::string> res = generateParenthesis(3);
    for (auto i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}