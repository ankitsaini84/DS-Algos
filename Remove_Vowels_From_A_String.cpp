/**
 * Given a string s, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it,
 * and return the new string.
 * 
 * EXAMPLE:
 * Input: s = "codingisfunandfuniscoding"
 * Output: "cdngsfnndfnscdng"
 * 
 * EXAMPLE:
 * Input: s = "aeiou"
 * Output: "" 
 */
#include <iostream>
#include <string>

class Solution {
    public:
        std::string removeVowels(std::string s) {
            // Just iterate over the string & keep adding the alphabet to
            // resultant string - if it is NOT a vowel.
            int length = s.length();
            int j {0};
            for(int i {0}; i < length; ++i) {
                if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
                    s[j++] = s[i];
                }
            }
            s.resize(j);
            return s;
        }
};

int main() {
    Solution s;
    std::string str {"codingisfunandfuniscoding"};
    std::string result = s.removeVowels(str);
    std::cout << result;
    return 0;
}