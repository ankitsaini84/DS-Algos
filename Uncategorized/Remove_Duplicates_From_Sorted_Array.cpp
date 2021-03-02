#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(static_cast<int>(nums.size()) == 0) return 0;
        int j {0};  // Mark 0 as Pivot
        for(int i {1}; i < static_cast<int>(nums.size()); ++i) {    // Iterate from 1
        // Iterate till ith element is equal to jth element..
            if(nums[i] != nums[j]) {
                // If there's a new element - place it next to previous unique element.
                nums[++j] = nums[i];
            }
        }
        // return total number of unique elements..
        return j+1;
    }
};

int main() {
    Solution s;
    std::vector<int> v {0, 0, 1, 1 ,1, 2, 2, 3, 3, 4};
    std::cout << "Answer : " << s.removeDuplicates(v);
    return 0;
}