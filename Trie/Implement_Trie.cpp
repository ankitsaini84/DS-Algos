/**
 * Implement a trie with insert, search, and startsWith methods.
 */

#include <iostream>
#include <string>
#include <vector>

class Trie {
    struct Node {
        Node* val[26] {nullptr, };
        bool eow {false};
    };

    Node* db {nullptr};
    
    int getVal(char c) {
        return c - 'a';
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        if(db == nullptr) {
            db = new Node();
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        int c;
        Node* curr {db};
        int len = static_cast<int>(word.length());
        for(int i {0}; i < len; ++i) {
            c = getVal(word[i]);
            
            if(curr->val[c] == nullptr) {
                curr->val[c] = new Node();
            }
            curr = curr->val[c];
        }
        curr->eow = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        int c;
        Node* curr {db};
        for(int i {0}; i < static_cast<int>(word.length()); ++i) {
            c = getVal(word[i]);
            if(curr->val[c] == nullptr) {
                return false;
            }
            curr = curr->val[c];
        }
        return curr->eow;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        int c;
        Node* curr {db};
        for(int i {0}; i < static_cast<int>(prefix.length()); ++i) {
            c = getVal(prefix[i]);
            if(curr->val[c] == nullptr) {
                return false;
            }
            curr = curr->val[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* trie = new Trie();

    trie->insert("apple");
    trie->search("apple");   // returns true
    trie->search("app");     // returns false
    trie->startsWith("app"); // returns true

    trie->insert("app");
    trie->search("app");     // returns true

    return 0;
}