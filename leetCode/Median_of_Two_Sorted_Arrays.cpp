#include <iostream>
#include <vector>
#include <algorithm>


double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    double res = 0;
    for (int i = 0; i < nums2.size(); ++i) {
        nums1.push_back(nums2[i]);
    }
    std::sort(nums1.begin(), nums1.end());
    int tmp1 = nums1.size() / 2;
    if (nums1.size() % 2 == 0)
        res = ((double)(nums1.at(tmp1 - 1) + nums1.at(tmp1))) / 2;
    else if (nums1.size() > 1)
        res = (double)nums1.at((nums1.size() + 1) / 2 - 1);
    else
        res = (double)nums1.at(0);
    return (res);   
}

int main()
{
    std::vector<int> a = {1, 3};
    std::vector<int> b = {2, 4};
    double res = findMedianSortedArrays(a, b);
    std::cout << "res : " << res << std::endl;
}