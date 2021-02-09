/**
 * Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that 
 * every key of the original BST is changed to the original key plus sum of all keys 
 * greater than the original key in BST.
 * 
 * EXAMPLE:
 * INPUT:
 *              4
 *            /   \
 *           1     6
 *         /  \   / \
 *        0    2 5   7
 *              \     \
 *               3     8
 * 
 * OUTPUT:
 *              30
 *            /    \
 *          36      21
 *         /  \    /  \
 *       36    35 26   15
 *              \        \
 *               33       8
 * 
 * 
 * CONSTRAINS:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
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
    int sum {0};
public:
    TreeNode* convertBST(TreeNode* root) {
        // return from leaf node
        if(!root) return nullptr;
        
        // Traverse Right subtree.
        convertBST(root->right);
        
        // Update self with previous sum
        // & then update sum with updated value
        root->val += sum;
        sum = root->val;
        
        // Traverse Left subtree
        convertBST(root->left);
        
        // propogate new updated root to parent
        return root;
    }
};

int main() {
    return 0;
}