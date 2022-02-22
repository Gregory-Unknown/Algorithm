#include <iostream>
#include <vector>


std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int>res;
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
                return (res);
            }
        }
    }
    return (res);
}

int main()
{
    std::vector<int> res = {2,7,11,15};
    res = twoSum(res, 26);
    std::cout << "res : " << std::endl;
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res.at(i) << std::endl;
    }

}