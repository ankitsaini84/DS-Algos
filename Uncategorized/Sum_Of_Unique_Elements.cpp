/**
 * You are given an integer array nums. The unique elements of an array are the
 * elements that appear exactly once in the array.
 * 
 * Return the sum of all the unique elements of nums.
 * 
 * EXAMPLE:
 * Input: nums = [1,2,3,2]
 * Output: 4
 * Explanation: The unique elements are [1,3], and the sum is 4.
 * 
 * EXAMPLE:
 * Input: nums = [1,1,1,1,1]
 * Output: 0
 * Explanation: There are no unique elements, and the sum is 0.
 * 
 * EXAMPLE:
 * Input: nums = [1,2,3,4,5]
 * Output: 15
 * Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.
 */

#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    int sumOfUnique(std::vector<int>& nums) {
        // By property, Maps stores only the unique keys.
        // Thus, we're going to store all the values as 'keys' in the map.
        // We'll keep adding all the elements in the vector stroing the
        // elements in the Map at the same time so that if a duplication is 
        // found, we'll remove the element from our sum.
        std::map<int, int> m {};
        std::map<int, int>::iterator it;
        int sum {0};

        // iterate through all the elements
        for(auto num : nums) {
            it = m.find(num);   // see if element is already present in the Map
            if(it == m.end()) {
                // if no, make it part of th sum, add the element to the Map
                sum += num;
                m.emplace(num, 0);
            } else {
                // if yes, subtract the previous addition of the element from
                // from the total sum; but, do it only once. Thus, do it only
                // if it has already not been incremented.
                if(it->second == 0) {
                    it->second = ++it->second;
                    sum -= num;
                }
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    std::vector v {1, 2, 3, 2};
    std::cout << "Sum of unique elements is " << s.sumOfUnique(v) << "\n";
    return 0;
}