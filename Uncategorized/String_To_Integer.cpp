/**
 * Implement the myAtoi(string s) function, which converts a string to a 32-bit signed 
 * integer (similar to C/C++'s atoi function).
 * 
 * The algorithm for myAtoi(string s) is as follows:
 * 
 * Read in and ignore any leading whitespace.
 * Check if the next character (if not already at the end of the string) is '-' or '+'. 
 * Read this character in if it is either. This determines if the final result is 
 * negative or positive respectively. Assume the result is positive if neither is 
 * present.
 * Read in next the characters until the next non-digit charcter or the end of the input 
 * is reached. The rest of the string is ignored.
 * Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits 
 * were read, then the integer is 0. Change the sign as necessary (from step 2).
 * If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp 
 * the integer so that it remains in the range. Specifically, integers less than -231 
 * should be clamped to -231, and integers greater than 231 - 1 should be clamped to 
 * 231 - 1.
 * Return the integer as the final result.
 *
 * NOTE:
 * Only the space character ' ' is considered a whitespace character.
 * Do not ignore any characters other than the leading whitespace or the rest of the 
 * string after the digits.
 * 
 * CONSTRAINTS:
 *  0 <= s.length <= 200
 *  s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', 
 * '-', and '.'.
 * 
 * EXAMPLE:
 * Input: s = "42"
 * Output: 42
 * 
 * EXAMPLE:
 * Input: s = "   -42"
 * Output: -42
 * 
 * EXAMPLE:
 * Input: s = "4193 with words"
 * Output: 4193
 * 
 * EXAMPLE:
 * Input: s = "words and 987"
 * Output: 0
 * 
 * EXAMPLE:
 * Input: s = "-91283472332"
 * Output: -2147483648
 * 
 * EXAMPLE:
 * Input: s = "200000000000000000000000000"
 * Output: 2147483648
 */


#include <iostream>
#include <string>

class Solution {
public:
    int myAtoi(std::string str) {
        int s {0};
        int sign {1};
        char c {};
        bool flag {false};
        long long num {0};

        // skip whitespaces
        while((c = str[s++]) == ' ');

        // determine sign of the integer
        if(!std::isdigit(c)) {
            if(c == '-') {
                sign = -1;
                ++s;
            } else if(c == '+') {
                ++s;
            } else {
                // if it is not a digit or valid sign - return 0.
                return 0;
            }
        }
        --s;    // rollback 1 iteration

        // form the integer
        while((c = str[s++]) && std::isdigit(c)) {
            c = c - '0';
                
            num = num * 10 + (sign * c);
            
            // brace for the impact - check for the valid integer range
            if(num < INT_MIN) {
                num = INT_MIN;
                break;
            } else if(num > INT_MAX) {
                num = INT_MAX;
                break;
            }
        }

        return num;
    }
};

int main() {
    Solution s;
    std::cout << "Answer : " << s.myAtoi("-91283472332");
    return 0;
}