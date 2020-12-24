/**
 * Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice.
 * You can return the answer in any order.
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 */
#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // The idea, here, is to use the map to store the array <value, index>
        // pair as we traverse the array, so that we don't have to search for
        // values by iterating through the array.
        // Main algo - 
        // Take a number from array & try to find the pairing number which
        // will add-up to form the target.
        std::map<int, int> m {};
        int length = nums.size();
        int diff {};
        for(int i {0}; i < length; ++i) {
            diff = target - nums[i];
            if(m.find(diff) != m.end()) {
                return std::vector<int> {m[diff], i};
            }
            m.emplace(nums[i], i);
        }
        return std::vector<int> {};
    }
};

int main() {
    std::vector<int> nums {2, 7, 11, 15};
    std::vector<int> result;
    Solution s;
    result = s.twoSum(nums, 9);
    std::cout << '[' << result[0] << "," << result[1] << ']';
    return 0;
}