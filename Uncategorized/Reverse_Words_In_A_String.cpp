/**
 * Given an input string s, reverse the order of the words.
 * A word is defined as a sequence of non-space characters. The words in s 
 * will be separated by at least one space.
 * 
 * Return a string of the words in reverse order concatenated by a single 
 * space.
 * 
 * Note that s may contain leading or trailing spaces or multiple spaces 
 * between two words. The returned string should only have a single space 
 * separating the words. Do not include any extra spaces.
 * 
 * EXAMPLE:
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 * 
 * EXAMPLE:
 * Input: s = "  hello world  "
 * Output: "world hello"
 * 
 * EXAMPLE:
 * Input: s = "a good   example"
 * Output: "example good a"
 * 
 * EXAMPLE:
 * Input: s = "  Bob    Loves  Alice   "
 * Output: "Alice Loves Bob"
 * 
 * EXAMPLE:
 * Input: s = "Alice does not even like bob"
 * Output: "bob like even not does Alice"
 * 
 * CONSTRAINTS:
 * 1 <= s.length <= 104
 * s contains English letters (upper-case and lower-case), digits, and 
 * spaces ' '.
 * There is at least one word in s.
 */

#include <iostream>
#include <string>

class Solution {
public:
    std::string reverseWords(std::string str) {
        int len {static_cast<int>(str.length())};
        char t;
        
        // reverse the whole string first
        for(int i {0}, j {len-1}; i < j ; ++i, --j) {
            t = str[i];
            str[i] = str[j];
            str[j] = t;
        }
        
        // reverse all the words in the reversed string to make them straighten up
        int i {0};
        int lwe {0};    // keeps track of "last word end"
        int wordFound {false};
        int lc {0};     // letters count
        
        // iterate till the end of the string
        while(i <= len) {
            if(wordFound && (str[i] == ' ' || i == len)) {
                for(int s {lwe}, e {i-1}; s <= e; --e, ++s) {
                    t = str[e];
                    str[e] = str[s];
                    str[s] = t;
                }
                // iterate - to find the end of last word..
                int j {lwe};
                while(j <= i) {
                    if(str[j] == ' ' || j == len) {
                        break;
                    }
                    ++lc;   // count letters
                    ++j;
                }
                ++lc;       // count the ' '.
                lwe = j+1;  // next word will start from ('last word' + ' ' + 1).
                wordFound = false;
            } else if(str[i] != ' ') {
                wordFound = true;
            }
            ++i;
        }
        
        str.resize(lc-1);   // decrement space for \0.
        
        return str;
    }
};

int main() {
    Solution s;
    std::cout << "Answer : " << s.reverseWords("    Bob    Loves    Alice    ");
    return 0;
}