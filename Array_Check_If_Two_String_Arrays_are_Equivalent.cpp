/**
 * Given two string arrays word1 and word2, return true if the 
 * two arrays represent the same string, and false otherwise.
 * A string is represented by an array if the array elements 
 * concatenated in order forms the string.
 * 
 * EXAMPLE:
 * Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
 * Output: true
 * Explanation:
 * word1 represents string "ab" + "c" -> "abc"
 * word2 represents string "a" + "bc" -> "abc"
 * The strings are the same, so return true.
 * 
 * EXAMPLE:
 * Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
 * Output: false
 * 
 * EXAMPLE:
 * Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
 * Output: true
 *
 * CONSTRAINTS:
 * 1 <= word1.length, word2.length <= 103
 * 1 <= word1[i].length, word2[i].length <= 103
 * 1 <= sum(word1[i].length), sum(word2[i].length) <= 103
 * word1[i] and word2[i] consist of lowercase letters.
 */

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, 
    std::vector<std::string>& word2) {
        std::string w1;
        for(const auto& s : word1) {
            w1.append(s);
        }

        std::string w2;
        for(const auto& s : word2) {
            w2.append(s);
        }

        return w1 == w2;
    }
};

int main() {
    std::vector<std::string> word1 {"abc", "d", "defg"};
    std::vector<std::string> word2 {"abcddefg"};

    Solution s;
    std::cout << "Solution: " << s.arrayStringsAreEqual(word1, word2) << '\n';
    return 0;
}
