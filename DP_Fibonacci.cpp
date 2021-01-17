/**
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence,
 * such that each number is the sum of the two preceding ones, starting from 0 and 1
 * That is,
 * F(0) = 0, F(1) = 1
 * F(n) = F(n - 1) + F(n - 2), for n > 1.
 * Given n, calculate F(n)
 */
#include <iostream>
#include <vector>
class Solution {
public:
    // DP - Memoisation
    int fib(const int k/*size*/) {
        // initialize memo w/ 1st 2 elements
        
        static std::vector<int> memo {0, 1};

        // check if present in memo. If yes, return from memo.
        if(static_cast<int>(memo.size()) > k) {
            return memo[k];
        }

        // assign to memo
        memo.push_back(fib(k-1) + fib(k-2));

        // return kth element from memo
        return memo.back();
    }
};

int main() {
    Solution s;
    std::cout << s.fib(9) << '\n';
    return 0;
}