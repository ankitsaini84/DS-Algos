/**
 * You are given an integer n.
 * An array nums of length n + 1 is generated in the following way:
 *  nums[0] = 0
 *  nums[1] = 1
 *  nums[2 * i] = nums[i] when 2 <= 2 * i <= n
 *  nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
 * Return the maximum integer in the array nums​​​.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0)  return 0;
        else if(n == 1 || n == 2) return 1;
        else {
            std::vector<int> nums (n+1, 0);  // 'n+1' ints initialised to '0'
            nums[0] = 0;
            nums[1] = 1;
            int max {0};
            int i {1};
            int l {0};
            int r {0};

            while(i <= n) {
                l = 2*i;
                if(l > n) {
                    break;
                }
                nums[l] = nums[i];

                r = l+1;
                if(r <= n) {
                    nums[r] = nums[i] + nums[i+1];

                    // 'l' will never be the max value as it is only being copied from
                    // previous values. Only 'r' value is the contender of being 'max'.
                    if(max < nums[r]) {
                        max = nums[r];
                    }
                }

                ++i;
            }

            return max;
        }
    }
};

int main() {
    Solution s;
    std::cout << "Solution : " << s.getMaximumGenerated(4) << '\n';
    return 0;
}