/**
 * Given two strings s and t , write a function to determine if t is an anagram of s.
 * 
 * EXAMPLE:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * EXAMPLE:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * You may assume the string contains only lowercase alphabets.
 */

#include <iostream>
#include <string>

constexpr int MAX_VALS {26}; // 'a' - 'z' = 26 characters
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int sIndexes[MAX_VALS] {0, };
        int tIndexes[MAX_VALS] {0, };
        int sLen {static_cast<int>(s.length())};
        
        if(sLen != static_cast<int>(t.length())) return false;
        
        for(int i {0}; i < sLen; ++i) {
            ++sIndexes[s[i] - 'a'];
            ++tIndexes[t[i] - 'a'];
        }
        
        for(int i {0}; i < MAX_VALS; ++i) {
            if(sIndexes[i] != tIndexes[i]) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution s;
    std::cout << s.isAnagram("anagram", "nagaram");

    return 0;
}