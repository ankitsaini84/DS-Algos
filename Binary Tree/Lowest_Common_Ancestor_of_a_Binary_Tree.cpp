/**
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the 
 * tree.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
 * between two nodes p and q as the lowest node in T that has both p and q as descendants 
 * (where we allow a node to be a descendant of itself).”
 * 
 * 
 *              3
 *            /   \
 *           5     1
 *         /  \   / \
 *        6    2 0   8
 *            / \
 *           7   4
 * 
 * EXAMPLE:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * 
 * EXAMPLE:
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself 
 * according to the LCA definition.
 * 
 * EXAMPLE:
 * Input: root = [1,2], p = 1, q = 2
 * Output: 1
 * 
 * CONSTRAINTS:
 * The number of nodes in the tree is in the range [2, 105].
 * -109 <= Node.val <= 109
 * All Node.val are unique.
 * p != q
 * p and q will exist in the tree.
 */

#include <iostream>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Algo ~
 * When @ a node, if we have both Left & Right nodes (p & q), we are standing on the
 * Least Common Ancestor node of p & q.
 * Thus, keep propogating current node as the answer.
 * 
 * But, if not, keep searching in left & right subtrees.
 * 
 * If either of the p or q is found, keep propogating the node as left/right found node.
 * And, if both are found, propogate root as the answer.
 * 
 * Else, if neither left or right is found, return nullptr.
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root == p || root == q) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right) {
            return root;
        }
        else if(left) {
            return left;
        }
        else if(right) {
            return right;
        }
        
        return nullptr;
    }
};

int main() {
    return 0;
}