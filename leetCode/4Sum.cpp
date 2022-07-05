#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {

    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    for(int i = 0; i < n - 3; ++i)
    {
        if((long)nums[i] + (long)nums[i + 1] + (long)nums[i + 2] + (long)nums[i + 3] > (long)target) break;
        if((long)nums[i] + (long)nums[n - 1] + (long)nums[n - 2] + (long)nums[n - 3] < (long)target) continue;

        for(int j = i + 1; j< n - 2; ++j)
        {
            if((long)nums[j] + (long)nums[j + 1] + (long)nums[j + 2] > (long)target - nums[i]) break;
            if((long)nums[j] + (long)nums[n - 1] + (long)nums[n - 2] < (long)target - (long)nums[i]) continue;
            int newTarget = target - nums[i] - nums[j];
            int start = j + 1;
            int end = n - 1;

            while(start < end)
            {
                if(nums[start] + nums[end] < newTarget)
                    ++start;
                else if(nums[start] + nums[end] > newTarget)
                    --end;
                else
                {
                    res.push_back({nums[i], nums[j], nums[start], nums[end]});
                    ++start;
                    --end;
                    while(start < end && nums[start] == res.back()[2]) start++;
                    while(start < end && nums[end] == res.back()[3]) end--;
                }
            }
            while(j + 1 < n && nums[j] == nums[j + 1]) ++j;
        }
        while(i + 1 < n && nums[i] == nums[i + 1]) ++i;
    }
    return res;
}

int main () {
    std::vector<int> num{1,0,-1,0,-2,2};
    std::vector<std::vector<int>> res = fourSum(num, 0);
    for (auto i : res) {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
}