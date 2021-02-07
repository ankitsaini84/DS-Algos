/**
 * Invert a binary tree.
 * 
 * EXAMPLE:
 * Input:
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * 
 * Output:
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 */
#include <iostream>

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) {     // Return when @ leaf node
            return nullptr;
        }
        
        TreeNode* left = invertTree(root->left);    // Get left subtree
        TreeNode* right = invertTree(root->right);  // Get right subtree
        
        // Exchange right & left subtrees
        root->right = left;
        root->left = right;
        
        // return the node
        return root;
    }
};

int main() {
    return 0;
}