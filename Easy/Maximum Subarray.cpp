/**
 * Given an integer array nums, find the contiguous subarray 
 * (containing at least one number) which has the largest sum and return 
 * its sum.
 * Example 1:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int length = nums.size();
        int sum {nums[0]};
        int hsum {nums[0]};
       for(int i {1}; i < length; ++i) {
           if(sum < 0 && nums[i] > 0) {
               sum = nums[i];
           } else {
               sum += nums[i];
           }
           if(sum > hsum) {
               hsum = sum;
           } else if(nums[i] > hsum) {
               hsum = nums[i];
           }
       }
        return hsum;
    }
};

int main() {
    Solution s;
    std::vector<int> nums {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << s.maxSubArray(nums);
    return 0;
}