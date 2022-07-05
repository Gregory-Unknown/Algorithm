#include <iostream>

class Solve {
    private:
    std::string &_s, &_p;
    public:
    Solve(std::string &s, std::string &p) : _s(s), _p(p) {}
    
    bool solve(int n, int m) {
        
        if (n == 0) {
            while (m > 0 && _p[m-1] == '*')
                m -= 2;
            if (m == 0) return true;
            return false;
        }
        if (m == 0) return false;
        
        if (_p[m-1] == '*') {
            if (_p[m-2] == _s[n-1] || _p[m-2] == '.')
                return solve(n-1, m) || solve(n, m-2);
            return solve(n, m-2);
        }
        if (_p[m-1] == '.' || _p[m-1] == _s[n-1])
            return solve(n-1, m-1);
        
        return false;
    }
    
    bool solve() {
        return solve(_s.size(), _p.size());
    }
};

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        
        return Solve(s,p).solve();
    }
};
int main()
{
    Solution sol;
    std::cout << sol.isMatch("aab", "c*a*b") << std::endl;
}