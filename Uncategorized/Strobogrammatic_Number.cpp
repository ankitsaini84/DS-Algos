/**
 * Given a string num which represents an integer, return true if num is a 
 * strobogrammatic number.
 * 
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees 
 * (looked at upside down).
 * 
 * EXAMPLE:
 * Input: num = "69"
 * Output: true
 * 
 * EXAMPLE:
 * Input: num = "88"
 * Output: true
 * 
 * EXAMPLE:
 * Input: num = "962"
 * Output: false
 */

#include <iostream>
#include <string>

/**
 * ALGORITHM:
 * 1. Read the number in inverse order.
 * 2. Replace the digits with their mirror counter-parts.
 * 3. Keep forming the new number with mirrored digits.
 * 4. In the end, if both the numbers are same -- the number is strobogrammatic.
 */

class Solution {
public:
    bool isStrobogrammatic(std::string num) {
        std::string rotated = "";
        for(int i {static_cast<int>(num.length()) - 1}; i >= 0; --i) {
            switch(num[i]) {
                case '0':
                    rotated.append("0");
                    break;
                case '1':
                    rotated.append("1");
                    break;
                case '6':
                    rotated.append("9");
                    break;
                case '8':
                    rotated.append("8");
                    break;
                case '9':
                    rotated.append("6");
                    break;
                default:
                    return false;
            }
        }
        if(rotated == num) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    std::cout << "Answer : " << s.isStrobogrammatic("69");
    return 0;
}