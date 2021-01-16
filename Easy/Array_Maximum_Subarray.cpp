/**
 * Given an integer array nums, find the contiguous subarray 
 * (containing at least one number) which has the largest sum and return 
 * its sum.
 * EXAMPLE:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * 
 * NOTE: [4,-1,2,1] has the largest sum = 6.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        // Observations : Unless, all the numbers in the array are negative,
        // series will ALWAYS start with a +ive number in the array.
        // Algo ~
        // 1. If the sum on left is -ive & current number is +ive - reject sum so far.
        // 2. Keep adding the sum.
        // 3. If, sum > highest sum, make sum as new highest sum.
        // 4. Also, consider current number to be of highest sum.
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