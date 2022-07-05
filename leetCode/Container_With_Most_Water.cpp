#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:

    int maxArea(std::vector<int>& height) {
        int start = 0, finish = height.size() - 1, res = INT_MIN;
        while (start < finish) {
            res = std::max(res, std::min(height[start], height[finish]) * (finish - start));
            if (height[start] < height[finish])
                ++start;
            else
                --finish;
        }
        return (res);
    }
};

int main() {
    Solution sol;
    std::vector<int> vec {2,3,4,5,18,17,6};
    std::cout << sol.maxArea(vec) << std::endl;
}