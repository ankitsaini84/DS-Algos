/**
 * Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
 * 
 * EXAMPLE:
 * Input: n = 00000000000000000000000000001011
 * Output: 3
 * 
 * EXAMPLE:
 * Input: n = 00000000000000000000000010000000
 * Output: 1
 * 
 * EXAMPLE:
 * Input: n = 11111111111111111111111111111101
 * Output: 31
 * 
 */

#include <iostream>

/**
 * Algo ~
 * Keep eliminating all 1s in the binary by AND-ing number by number-1.
 * Since, the trailing 1 at the righmost bit will get eliminated everytime the number is AND-ed by its predecessor.
 * Keep doing it, till the number ends in 0.
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int noOfBits {0};
        while(n > 0) {
            n = n & (n-1);
            ++noOfBits;
        }
        return noOfBits; 
    }
};

int main() {
    Solution s;
    std::cout << "Answer : " << s.hammingWeight(7);
    return 0;
}