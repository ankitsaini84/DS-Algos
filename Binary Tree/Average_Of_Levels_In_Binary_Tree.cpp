/**
 * Given a non-empty binary tree, return the average value of the nodes on 
 * each level in the form of an array.
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
public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode> q;
        std::vector<double> v;
        
        if(root == nullptr) return v;
        
        double level_sum {0.0};
        int level_size {1};
        int reducing_size {1};
        TreeNode n {};
        double avg {0.0};
        
        q.push(*root);
        level_size = static_cast<int>(q.size());
        while(!q.empty()) {
            n = q.front();
            q.pop();
            --reducing_size;
            
            // sum up the nodes for the level
            level_sum += n.val;
            
            // push left & right nodes of the tree
            if(n.left) {
                q.push(*n.left);
            }
            
            if(n.right) {
                q.push(*n.right);
            }
            
            // end of level
            if(reducing_size == 0) {
                // push average to the std::vector
                avg = level_sum / level_size;
                v.push_back(avg);
                
                // reset vars
                avg = 0.0;
                level_sum = 0;
                
                // reset level size
                level_size = static_cast<int>(q.size());
                reducing_size = level_size;
            }
        }
        
        return v;
    }
};

int main() {
    return 0;
}