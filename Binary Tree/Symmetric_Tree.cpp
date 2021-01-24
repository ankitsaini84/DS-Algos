/**
 * Given a binary tree, check whether it is a mirror of itself 
 * (i.e., symmetric around its center)
 * 
 * EXAMPLE: [1,2,2,3,4,4,3]         -> symmetric.
 * EXAMPLE: [1,2,2,null,3,null,3]   -> asymmetric.
 */
#include <iostream>
#include <vector>

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
 * A Tree is SYMMETRIC, if its RIGHT subtree is a MIRROR image of its LEFT subtree.
 * Algo ~
 * To determine if current nodes are symmetric - determine whether..
 * 1. both left & right child nodes are present OR both are absent.
 * 2. If present, left-child value == right-child value.
 * 3. If left->left subree is mirror image of right->right subtree AND
 * 4. If left->right subtree is mirror image of right->left subtree.
 * 
 * If all the conditions are met, it's a Symmetric Tree.
 */
class Solution {
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        // Either both nodes should be absent
        if(!left && !right) return true;
        
        return((left && right) &&       // OR, both nodes should be present
           (left->val == right->val) && // And, if present, values should be same
           isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        if(isSymmetric(root->left, root->right)) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    return 0;
}