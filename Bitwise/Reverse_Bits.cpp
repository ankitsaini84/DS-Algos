/**
 * Reverse bits of a given 32 bits unsigned integer.
 * Follow up:
 * If this function is called many times, how would you optimize it?
*/

#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n == 0) {
            return n;
        }
        
        int lastBit {0};
        uint32_t newN {0};
        int i {0};
        
        while(n) {                  // traverse till 'n' becomes 0.
            lastBit = n & 1;        // fetch last bit from 'n'.
            n = n >> 1;             // shift right to fetch next available (left) bit.
            
            newN = newN << 1;       // make space for new number - shift left.
            newN = newN | lastBit;  // put fetched number (from above) at last position 
                                    // of the new number.
            ++i;                    // keep counting bits
        }

        // Check if we have any pending 0s to be pushed to fill the 32 bit new number.
        // If yes, push the remaining bits at the end.
        newN = newN << (32 - i);    
        
        return newN;
    }
};

int main() {
    Solution s;
    std::cout << "Answer : " << s.reverseBits(10);
    return 0;
}