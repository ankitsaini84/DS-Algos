/**
 * Given a string s consisting only of letters 'a' and 'b'. In a single step you can 
 * remove one palindromic subsequence from s.
 * 
 * Return the minimum number of steps to make the given string empty.
 * 
 * A string is a subsequence of a given string, if it is generated by deleting some 
 * characters of a given string without changing its order.
 * 
 * A string is called palindrome if is one that reads the same backward as well as 
 * forward.
 * 
 * EXAMPLE:
 * Input: s = "ababa"
 * Output: 1
 * 
 * EXAMPLE:
 * Input: s = "abb"
 * Output: 2
 * 
 * EXAMPLE:
 * Input: s = "baabb"
 * Output: 2
 * 
 * CONSTRAINTS:
 * 0 <= s.length <= 1000
 * s only consists of letters 'a' and 'b'
 */

#include <iostream>
#include <string>

/**
 * Solution:
 * Since the question asks only for palindromic sub-sequence - 
 * It necessarily may not be CONTINUOUS.
 * And, since only 2 alphabets are present - 'a' & 'b'..
 * We can create 2 discontinous subsequences by collection all a's & all b's in 2 groups.
 * And then delete them both as palindromes.
 * e.g. abababbababbaaaabbababab
 * -> a's sequence -> aaaaaaaaaaaaa
 * -> b's sequence -> bbbbbbbbbbbb
 * Both sequences are pallindromes. delete them in 2 shots.
 * So, the max. answer is 2.
 */

class Solution {
public:
    int removePalindromeSub(std::string s) {
        if(s.length() == 0) return 0;
        for(int i {0}, j {static_cast<int>(s.length())-1}; i < j; ++i, --j) {
            if(s[i] != s[j]) {
                return 2;
            }
        }
        return 1;
    }
};

int main() {
    Solution s;
    std::cout << "Answer : " << s.removePalindromeSub("baabb");
    return 0;
}