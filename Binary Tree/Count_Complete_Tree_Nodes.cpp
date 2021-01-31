/**
 * Given the root of a complete binary tree, return the number of the nodes in the tree.
 * 
 * EXAMPLE:
 * Input: root = [1,2,3,4,5,6]
 *          1
 *        /   \
 *       2     3
 *     /  \   /
 *    4    5 6
 * Output: 6
 */
#include <iostream>

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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        // Collect node count from left & right children
        int left {countNodes(root->left)};
        int right {countNodes(root->right)};
        
        // Node count = nodes collected from left child + 
        // nodes collected from right child + root (1).
        return left + right + 1;
    }
};

int main(void) {
    return 0;
}