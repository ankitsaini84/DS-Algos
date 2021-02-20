/**
 * Given a signed 32-bit integer x, return x with its digits reversed. If reversing x 
 * causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then 
 * return 0.
 * 
 * Assume the environment does not allow you to store 64-bit integers (signed or 
 * unsigned).
 * 
 * CONSTRAINTS:
 * -2^31 <= x <= 2^31 - 1
 */
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int d;
        int answer {0};
        constexpr int max {INT_MAX / 10};
        constexpr int min {INT_MIN / 10};
        constexpr int lastMaxDigit {INT_MAX % max};
        constexpr int lastMinDigit {INT_MIN % min};
        
        while(x) {
            d = x % 10;
            x = x / 10;
            if(answer > max || (answer == max && d > lastMaxDigit)) {
                answer = 0;
                break;
            }
            if(answer < min || (answer == min && d < lastMinDigit)) {
                answer = 0;
                break;
            }
            answer = answer * 10 + d;
        }
        return answer;
    }
};

int main() {
    Solution s;
    std::cout << "Answer : " << s.reverse(123456789);
    return 0;
}