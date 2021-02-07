/**
 * Given a binary tree, imagine yourself standing on the right side of it, return
 * the values of the nodes you can see ordered from top to bottom.
 * 
 * EXAMPLE:
 *              1 --------> 1
 *            /   \
 *           2     3 -----> 3
 *            \   /  \
 *             5 4    6 --> 6
 *                \
 *                 7 -----> 7
 * 
 * INPUT: [1,2,3,null,5,4,6,null,null,null,7]
 * OUTPUT: [1,3,6,7]
 */
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    std::vector<int> answer {};
    
    void helper(TreeNode* node, int level) {
        if(!node) return;               // Return @ leaf node
        
        // If we have yet not submitted any aswer for this level - submit
        // the answer i.e. Rightmost node, since we always traverse right-first.
        if(level == static_cast<int>(answer.size())) {
            answer.push_back(node->val);
        }

        helper(node->right, level+1);   // First go RIGHT
        helper(node->left, level+1);    // Go LEFT next
    }
public:
    std::vector<int> rightSideView(TreeNode* root) {
        helper(root, 0);
        return answer;
    }
};

int main() {
    return 0;
}