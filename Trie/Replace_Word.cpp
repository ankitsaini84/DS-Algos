/**
 * In English, we have a concept called root, which can be followed by some other word to 
 * form another longer word - let's call this word successor. For example, when the root 
 * "an" is followed by the successor word "other", we can form a new word "another".
 * 
 * Given a dictionary consisting of many roots and a sentence consisting of words 
 * separated by spaces, replace all the successors in the sentence with the root forming 
 * it. If a successor can be replaced by more than one root, replace it with the root 
 * that has the shortest length.
 * 
 * Return the sentence after the replacement.
 * 
 * EXAMPLE:
 * Input:   dictionary = ["cat","bat","rat"], 
 *          sentence = "the cattle was rattled by the battery"
 * Output:  "the cat was rat by the bat"
 * 
 * EXAMPLE:
 * Input:   dictionary = ["a","b","c"], 
 *          sentence = "aadsfasf absbs bbab cadsfafs"
 * Output:  "a a b c"
 * 
 * EXAMPLE:
 * Input:   dictionary = ["a", "aa", "aaa", "aaaa"], 
 *          sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
 * Output:  "a a a a a a a a bbb baba a"
 * 
 * CONSTRAINTS:
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 100
 * dictionary[i] consists of only lower-case letters.
 * 1 <= sentence.length <= 10^6
 * sentence consists of only lower-case letters and spaces.
 * The number of words in sentence is in the range [1, 1000]
 * The length of each word in sentence is in the range [1, 1000]
 * Each two consecutive words in sentence will be separated by exactly one space.
 * sentence does not have leading or trailing spaces.
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
    struct Node {
        Node* children[26] {nullptr, };
        bool eow {false};
    };
    
    class Trie {
        Node trie;
        int getVal(char c) {
            return c - 'a';
        }
        public:
        void add(std::string& word) {
            int len {static_cast<int>(word.length())};
            Node* crawl {&trie};
            for(int i {0}; i < len; ++i) {
                int v = getVal(word[i]);
                if(crawl->children[v] == nullptr) {
                    crawl->children[v] = new Node();
                }
                crawl = crawl->children[v];
            }
            crawl->eow = true;
        }
        
        int get(std::string& word) {
            Node* crawl {&trie};
            int len {static_cast<int>(word.length())};
            // std::string prefix {word};
            for(int i {0}; i < len; ++i) {
                int v = getVal(word[i]);
                if(crawl->children[v] != nullptr) {
                    if(crawl->children[v]->eow == true) {
                        return i+1;
                    }
                    crawl = crawl->children[v];
                } else {
                    return len;
                }
            }
            return len;
        }
    };
public:
    std::string replaceWords(std::vector<std::string>& dictionary, std::string sentence) {
        Trie db;
        // Insert all the words in dictionary in the Trie.
        for(auto word : dictionary) {
            db.add(word);
        }
        
        std::string result = "";
        int len {static_cast<int>(sentence.length())};
        int ps {0};
        int n {0};
        int i {0};
        std::string word;
        // Iterate all the words in the sentence
        while(i < len) {
            if(sentence[i] == ' ') {
                // search for the word in trie
                word = sentence.substr(ps, i-ps);
                // trie will return the number letters which were found 
                // -- as part of dictionary.
                // if not, it'll return whole length of the word.
                n = db.get(word);
                // take substring out of word of n length & append it to our result
                // followed by ' '.
                result.append(word.substr(0, n));
                result.append(" ");
                ps = i+1; // skip space
            }
            ++i;
        }
        // consider last word in the sentence
        word = sentence.substr(ps, i-ps);
        n = db.get(word);
        result.append(word.substr(0, n));
        
        return result;
    }
};

int main() {
    Solution s;
    std::vector<std::string> dictionary {"cat", "rat", "bat"};
    std::cout << "Answer : " << s.replaceWords(dictionary, "the cattle was rattled by the battery") << "\n";
    return 0;
}