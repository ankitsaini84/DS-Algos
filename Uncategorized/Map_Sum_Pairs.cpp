/**
 * MapSum() Initializes the MapSum object.
 * 
 * void insert(String key, int val) Inserts the key-val pair into the map. If the key 
 * already existed, the original key-value pair will be overridden to the new one.
 * 
 * int sum(string prefix) Returns the sum of all the pairs' value whose key starts with 
 * the prefix
 * 
 * EXAMPLE:
 * Input:
 * ["MapSum", "insert", "sum", "insert", "sum"]
 * [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
 * Output: 
 * [null, null, 3, null, 5]
 * 
 * CONSTRAINTS:
 * 1 <= key.length, prefix.length <= 50
 * key and prefix consist of only lowercase English letters.
 * 1 <= val <= 1000
 * At most 50 calls will be made to insert and sum.
 */

#include <iostream>
#include <string>
#include <stack>

class MapSum {
    struct Node {
        Node* children[26] {nullptr, };
        bool eok {false};                   // end of key
        int val {0};                        // stores value of the key (@ eok)
        int sum {0};                        // sum of overlapping values
    };
    
    class Trie {
        Node* db {nullptr};
        int getVal(char c) {
            return c - 'a';
        }
        public:
        Trie() : db(new Node()) {};
        
        void add(std::string key, int val) {
            Node* curr {db};                // currsor
            int len {static_cast<int>(key.length())};
            std::stack<Node*> visited;      // store pointers to all visited elements

            for(int i {0}; i < len; ++i) {
                int v = getVal(key[i]);

                if(curr->children[v] == nullptr) {
                    // insert new node
                    curr->children[v] = new Node();
                    curr->children[v]->sum = val;
                } else {
                    // add value to old node's sum
                    curr->children[v]->sum += val;
                }
                // to be used to update sum if key is updated
                visited.push(curr->children[v]);
                curr = curr->children[v];   // iterate to children
                
                if(i == len-1) {            // reached eok
                    if(curr->eok == false) {// inserting 1st time..
                        curr->eok = true;   // mark end of key
                        curr->val = val;    // update value of this key
                    } else {                // already inserted key..
                        // evalute difference
                        int diff {curr->val - val};
                        diff += val;
                        curr->val = val;    // update new key
                        
                        // iterate visited stack & update sum for all keys
                        while(!visited.empty()) {
                            (visited.top())->sum -= diff;
                            visited.pop();
                        }
                    }
                }
            }
        }
        
        int get(std::string key) {
            if(db == nullptr) return 0;
            Node* curr {db};
            for(int i {0}; i < static_cast<int>(key.length()); ++i) {
                int v = getVal(key[i]);
                
                if(curr->children[v] == nullptr) {
                    return 0;
                }
                
                curr = curr->children[v];
            }
            return curr->sum;
        }
    };
public:
    /** Initialize your data structure here. */
    Trie* db {nullptr};
    MapSum() {
        db = new Trie();
    }
    
    void insert(std::string key, int val) {
        db->add(key, val);
    }
    
    int sum(std::string prefix) {
        return db->get(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
int main() {
    return 0;
}