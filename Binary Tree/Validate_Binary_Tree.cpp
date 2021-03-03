/**
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * NOTE: A valid BST is defined as follows:
 *  1. The left subtree of a node contains only nodes with keys less than the node's key.
 *  2. The right subtree of a node contains only nodes with keys greater than the node's key.
 *  3. Both the left and right subtrees must also be binary search trees.
 * 
 * CONSTRAINTS:
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
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

/**
 * Algo ~
 * As per property of a BST, each left node should be less than it's parent 
 * & right node should be greater than the parent.
 * Thus, Root node has a restriction boundary of -inf. to +inf.
 * It's left child will have restriction boundary of -inf. to root->val.
 * Similary, it's right child will have restriction boundary of root->val to +inf.
 * If a node is it's defined range & its children also adhers to the same - it's a BST.
 */
class Solution {
    bool helper(TreeNode* root, long leftBound, long rightBound) {
        if(root == nullptr) return true;                                // reached leaf node
        
        if(root->val > leftBound && root->val < rightBound) {           // boundary check
            bool left = helper(root->left, leftBound, root->val);       // left sub-tree
            bool right = helper(root->right, root->val, rightBound);    // right sub-tree
            if(left && right) {                                         // if both are valid
                return true;
            }
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);  // Since, boundary is from -2^31 to 2^31 - 1.
    }
};

int main() {
    return 0;
}