/**
 *  Given a binary tree, you need to compute the length of the diameter of the tree. The diameter
 * of a binary tree is the length of the longest path between any two nodes in a tree. This path
 * may or may not pass through the root.
 * EXAMPLE:
 * Given a binary tree 
 *      1
 *     / \
 *    2   3
 *   / \
 *  4   5
 * 
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * NOTE: The length of path between two nodes is represented by the number of edges between them.
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
    int diameter {0};
    
    int max(const int a, const int b) {
        return a > b ? a : b;
    }
    
    int helper(TreeNode* root) {
        if(!root) return 0;
        
        // Evaluate both left & right subtrees
        int left { helper(root->left) };
        int right { helper(root->right) };
        
        // New diameter = left + right subtree's diameter
        // Update the largest yet diameter as answer
        diameter = max(diameter, left + right);
        
        // cout << root->val << ' ' << diameter << '\n';
        // Though, since, maximum yet diameter can not be a part of the diameter-path
        // we have to propogate above. It should be the largest of left or right path
        // + 1; & not, left path + right path + 1.
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return diameter;
    }
};

int main() {
    return 0;
}