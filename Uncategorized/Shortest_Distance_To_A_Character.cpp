/**
 * Given a string s and a character c that occurs in s, return an array of integers 
 * answer where answer.length == s.length and answer[i] is the shortest distance from
 * s[i] to the character c in s.
 * 
 * EXAMPLE:
 * Input: s = "loveleetcode", c = "e"
 * Output: [3,2,1,0,1,0,0,1,2,2,1,0]
 * 
 * EXAMPLE:
 * Input: s = "aaab", c = "b"
 * Output: [3,2,1,0]
 */
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> shortestToChar(std::string s, char c) {
        std::vector<int> answer {};

        int d {0};
        int pd {-1};
        for(int i {0}; i < s.length(); ++i, ++d) {
            answer.push_back(d);
            if(s[i] == c) {
                int j {i};
                int td {0};
                int l = (pd == -1 ? 0 : pd + ((d+1) / 2));
                
                while(j >= l && j > pd) {
                    answer[j] = td;
                    --j;
                    ++td;
                }
                pd = i; // reset pd
                d = 0;  // reset d
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    std::vector<int> result = s.shortestToChar("baaa", 'a');
    for(auto e : result) {
        std::cout << e << " ";
    }
    return 0;
}