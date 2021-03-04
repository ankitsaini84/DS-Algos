/**
 * 
 */
#include <iostream>
#include <vector>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    void reverse(std::vector<int> &v) {
        int len {static_cast<int>(v.size())};
        int t;
        for(int s {0}, e {len - 1}; s < e; ++s, --e) {
            t = v[s];
            v[s] = v[e];
            v[e] = t;
        }
    }
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> answer;
        
        if(!root) return answer;
        
        std::queue<TreeNode> q;  // queue for tree traversal
        std::vector<int> v;      // temporary vector to store level nodes
        TreeNode node;      // used as iterator
        int level_size {1}; // number of nodes left to traverse in current level
        bool isOdd {true};  // is level odd ?
        
        q.push(*root);
        while(!q.empty()) {
            node = q.front();
            q.pop();
            --level_size;
            v.push_back(node.val);
            
            if(node.left) {
                q.push(*node.left);
            }
            if(node.right) {
                q.push(*node.right);
            }
            
            if(level_size == 0) {       // Current level is over
                if(!isOdd) reverse(v);  // reverse the order if level is even
                answer.push_back(v);    // push the temperory vector to answer
                v.clear();              // clear temporary vector
                level_size = q.size();  // reset number of nodes to traverse for next level
                // Toggle even-odd
                isOdd = isOdd ? false : true;
            }
        }
        
        return answer;
    }
};

int main() {
    return 0;
}