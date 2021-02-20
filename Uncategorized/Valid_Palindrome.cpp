/**
 * Given a string s, determine if it is a palindrome, considering only alphanumeric 
 * characters and ignoring cases.
 * 
 * CONSTRAINTS:
 * 1 <= s.length <= 2 * 105\
 * s consists only of printable ASCII characters.
 * 
 * EXAMPLE:
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * EXAMPLE:
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 */

#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string str) {
        int s {0};
        int e {static_cast<int>(str.length()) - 1};
        int sc, ec;
        while(s <= e) {
            sc = str[s];
            if(std::isalpha(sc) || std::isdigit(sc)) {
                sc = std::tolower(sc);
            } else {
                ++s;
                continue;
            }
            ec = str[e];
            if(std::isalpha(ec) || std::isdigit(ec)) {
                ec = std::tolower(ec);
            } else {
                --e;
                continue;
            }
            
            if(sc != ec) {
                return false;
            }
            ++s;
            --e;
        }
        return true;
    }
};


int main() {
    Solution s;
    std::cout << s.isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}