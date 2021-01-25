/**
 * Given the root of a binary tree, return the number of uni-value subtrees.
 * A uni-value subtree means all nodes of the subtree have the same value.
 * 
 * EXAMPLE:
 * Input: root = [5,1,5,5,5,null,5]
 * Output: 4
 * 
 * EXAMPLE:
 * Input: root = []
 * Output: 0
 * 
 * EXAMPLE:
 * Input: root = [5, 5, 5, 5, 5, null, 5]
 * Output: 6
 * 
 * CONSTRAINTS:
 * The numbrt of the node in the tree will be in the range [0, 1000].
 * -1000 <= Node.val <= 1000.
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
/**
 * IMP: INTUITION:
 * Given a node in our tree, we know that it is a universal subtree 
 * if it meets one of the following conditions..
 * 
 * 1. The node has no children (base condition)
 * 2. All of the node's children are univalue sybtrees, 
 * & the node and its children all have the same value.
 * 
 * With this in mind, we can perform depth-first search on our tree, 
 * & test if each subtree is uni-value - in a bottom-up manner
 * 
 */
class Solution {
    int count {0};
    bool helper(TreeNode* node) {
        // Identify leaf node - if yes, increment count.
        if(!node->left && !node->right) {
            ++count;
            return true;
        }

        bool isUniVal {true};
        // If node has a left child, & its left-child's value is equal to its value
        // - it is a univalue tree
        if(node->left) {
            isUniVal = helper(node->left) && isUniVal && (node->val == node->left->val);
        }

        // Similarly, If node has a right child, & its right-child's value is equal to its value
        // & also, node's left child was a uni-value subtree
        // - it is a univalue tree
        if(node->right) {
            isUniVal = helper(node->right) && isUniVal && (node->val == node->right->val);
        }

        // If both left & right subtrees are uni-value trees, then increment count
        if(!isUniVal) {
            return false;
        } else {
            ++count;
            return true;
        }
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return count;
    }
};

int main() {
    return 0;
}