#include <iostream>
#include <vector>
#include <algorithm>

int threeSumClosest(std::vector<int>& nums, int target)
{
    int res = nums[0] + nums[1] + nums[2];
    int tmp = 0;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r) {
            tmp = nums[i] + nums[l] + nums[r];
            if (abs(target - tmp) < abs(target - res))
                res = tmp;
            if (tmp == target)
                return target;
            else if (tmp > target)
                --r;
            else if (tmp < target)
                ++l;
        }
    }
    return res;
}

int main() {
    std::vector<int>nums {-1,2,1,-4};
    int res = threeSumClosest(nums, 1);
    std::cout << res << std::endl;
}