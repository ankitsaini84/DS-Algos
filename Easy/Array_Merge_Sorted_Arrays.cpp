/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * NOTE:
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 * You may assume that nums1 has enough space (size that is equal to m + n) to 
 * hold additional elements from nums2.
 * 
 * EXAMPLE:
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * Output: [1,2,2,3,5,6]
 */

#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int x {m - 1};
        int y {n - 1};
        int z {m + n - 1};

        while(x >= 0 && y >= 0) {
            if(nums1[x] > nums2[y]) {
                nums1[z] = nums1[x];
                --x;
            } else {
                nums1[z] = nums2[y];
                --y;
            }
            --z;
        }

        while(y >= 0) {
            nums1[z] = nums2[y];
            --y;
            --z;
        }
    }
};

int main() {
    std::vector<int> nums1 {4, 5, 6, 0, 0, 0};
    std::vector<int> nums2 {1, 2, 3};

    Solution s;
    s.merge(nums1, 3, nums2, 3);
    std::cout << "Solution : ";
    for(const int& i : nums1) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}