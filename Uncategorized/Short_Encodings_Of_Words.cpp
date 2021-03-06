/**
 * A valid encoding of an array of words is any reference string s and array 
 * of indices indices such that:
 * 
 * words.length == indices.length
 * The reference string s ends with the '#' character.
 * For each index indices[i], the substring of s starting from indices[i] and 
 * up to (but not including) the next '#' character is equal to words[i].
 * 
 * Given an array of words, return the length of the shortest reference 
 * string s possible of any valid encoding of words.
 * 
 * EXAMPLE:
 * Input: words = ["time", "me", "bell"]
 * Output: 10
 * Explaination: 
 * A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
 *  words[0] = "time", the substring of s starting from indices[0] = 0 to the
 *  next '#' is underlined in "time#bell#"
 * 
 *  words[1] = "me", the substring of s starting from indices[1] = 2 to the
 *  next '#' is underlined in "time#bell#"
 * 
 *  words[2] = "bell", the substring of s starting from indices[2] = 5 to the 
 *  next '#' is underlined in "time#bell#"
 * 
 * CONSTRAINTS:
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 7
 * words[i] consists of only lowercase letters.
 */

#include <iostream>
#include <algorithm>    // sort
#include <string>
#include <vector>

struct Node {
    Node* val[26] {nullptr, };
    // char count {0};
};

char getVal(char c) {
    return c - 'a';
}

class Solution {   
    class Trie {
        Node trie;
        public:
        bool add(std::string word) {
            int c;
            Node* curr {&trie};
            for(int i {static_cast<int>(word.length() - 1)}; i >= 0; --i) {
                c = getVal(word[i]);
                if(curr->val[c] == nullptr) {
                    curr->val[c] = new Node();
                    if(i == 0) {
                        return true;
                    }
                }
                curr = curr->val[c];
            }
            return false;
        }
    };
 struct compare {
    inline bool operator()(const std::string& first,
            const std::string& second) const
    {
        return first.size() > second.size();
    }
};

    class functor {
        public:
        bool operator() (const std::string& w1, const std::string& w2) const {
            return w1.size() > w2.size();
        }
    };
public:
/**
 * Algo ~
 * To find the suffix - add words in reverse order to a Trie.
 * If the word is added for the 1st time, add() returns 'true'.
 * If add() retuns true, add it's length to the answer.
 * 
 * NOTE: There could be a case when a smaller word is added, followed by a 
 * longer word. In this case, our add function could not return proper value.
 * Thus, to mitigate this loophole - sorted the vector to insert longer words 
 * followed by the shorter ones.
 */
    int minimumLengthEncoding(std::vector<std::string>& words) {
        Trie t;
        int answer {0};
        std::sort(words.begin(), words.end(), (functor()));
        
        for(auto& word : words) {
            if(t.add(word)) {
                answer += word.length() + 1;
            }
        }
        
        return answer;
    }
};

int main() {
    std::vector<std::string> words {"time", "me", "bell"};
    Solution s;
    std::cout << "Answer : " << s.minimumLengthEncoding(words) << "\n";
    return 0;
}