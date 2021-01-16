/**
 * Find the kth largest element in an unsorted array. 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * Example 2:
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * NOTE: You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::less<int>> pqueue;
        
        // insert all elements in priority queue
        for(const auto& i : nums) {
            pqueue.push(i);
        }

        // pop first k-th elements
        int result {0};
        while(k-- && !pqueue.empty()) {
            result = pqueue.top();
            pqueue.pop();
        }

        return result;
    }
};

int main() {
    Solution s;

    std::vector<int> v1 {3, 2, 1, 5, 6, 4};
    std::cout << "Solution : " << s.findKthLargest(v1, 2) << '\n';

    std::vector<int> v2 {3, 2, 3, 1, 2, 4, 5, 5, 6};
    std::cout << "Solution : " << s.findKthLargest(v2, 4) << '\n';

    return 0;
}