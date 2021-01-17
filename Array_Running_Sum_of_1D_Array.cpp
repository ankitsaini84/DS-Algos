/**
 * Given an array nums. We define a running sum of an array as
 * runningSum[i] = sum(nums[0]…nums[i]).
 * Return the running sum of nums.
 * 
 * EXAMPLE:
 * Input: nums = [1,2,3,4]
 * Output: [1,3,6,10]
 * Explanation: Running sum is obtained as follows: 
 * [1, 1+2, 1+2+3, 1+2+3+4].
 * 
 * EXAMPLE:
 * Input: nums = [1,1,1,1,1]
 * Output: [1,2,3,4,5]
 * Explanation: Running sum is obtained as follows: 
 * [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
 * 
 * EXAMPLE:
 * Input: nums = [3,1,2,10,1]
 * Output: [3,4,6,16,17]
 * 
 * CONSTRAINTS:
 * 1 <= nums.length <= 1000
 * -10^6 <= nums[i] <= 10^6
 */

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        std::vector<int> r;
        for(const auto& e : nums) {
            if(r.empty()) {
                r.push_back(e);
            } else {
                r.push_back(r.back() + e);
            }
        }
        return r;
    }
};

int main() {
    std::vector<int> nums {3, 1, 2, 10, 1};
    Solution s;
    nums = s.runningSum(nums);
    for(const auto& e : nums) {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}