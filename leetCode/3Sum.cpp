#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<std::vector<int>> res) {
    std::cout << "[";
    for (auto i : res) {
        int com = 0;
        std::cout << "[";
        for (auto j : i)
        {
            std::cout << j;
            if (com < 2)
                std::cout << ", ";
            ++com;
        }
        std::cout << "]";
    }
    std::cout << "]" <<  std::endl;
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> v;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < n - 2; ++i)
    {
        if(i == 0 || (i > 0 && nums[i] != nums[i-1]))
        {
            int l = i + 1;
            int r = n - 1;
            int target = 0 - nums[i];
            
            while(l < r)
            {
                if(nums[l] + nums[r] == target)
                {
                    v.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l + 1])
                        ++l;
                    while(l < r && nums[r] == nums[r - 1])
                        --r;
                    ++l;
                    --r;
                }
                else if(nums[l] + nums[r] > target)
                    --r;
                else 
                    ++l;
            }
        }
    }
    return v;
}

int main() {
    std::vector<int>nums {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> res = threeSum(nums);
    print(res);
}