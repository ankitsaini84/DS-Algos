/**
 * Given n non-negative integers representing an elevation map where the width of each 
 * bar is 1, compute how much water it can trap after raining.
 * 
 * EXAMPLE:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array 
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) 
 * are being trapped.
 * 
 * CONSTRAINTS:
 * n == height.length
 * 0 <= n <= 3 * 104
 * 0 <= height[i] <= 105
 */

#include <iostream>
#include <vector>

class Solution {
    int min(const int a, const int b) {
        return a < b ? a : b;
    }
    public:
    int trap(std::vector<int>& height) {
        std::vector<int> maxHeight;
        int max {0};
        int length = static_cast<int>(height.size());
        int trappedWater {0};
        
        // Moving Left to Right
        for(int i {0}; i < length; ++i) {
            if(height[i] > max) {
                // update max
                max = height[i];
            }
            maxHeight.push_back(max);
        }
        
        // Moving Right to left
        max = 0;
        for(int i {length - 1}; i >= 0; --i) {
            if(height[i] > max) {
                // update max
                max = height[i];
            }
            trappedWater += min(maxHeight[i], max) - height[i];
        }
        return trappedWater;
    }
};

int main() {
    Solution s;
    std::vector v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "Answer : " << s.trap(v);
    return 0;
}