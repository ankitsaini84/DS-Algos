/**
 * IN ORDER TRAVERSAL - Left - Root - Right
 * 
 * Given the root of a binary tree, return the inorder 
 * traversal of its nodes' values.
 * 
 * EXAMPLE:
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 * 
 * CONSTRAINTS:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * LINK: https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/929/
 */

#include <iostream>
#include <vector>
#include <stack>

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
    std::vector<int> r {};

    // Recursive Solution
    std::vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return r;   // break condition

        inorderTraversal(root->left);   // Go Left (if available)
        r.push_back(root->val);         // Read Root
        inorderTraversal(root->right);  // Go Right (if available)

        return r;                       // return final solution
    }

    std::vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> stack {};

        if(root == nullptr) return r;

        TreeNode* node {nullptr};
        stack.push(root);
        while(!stack.empty()) {
            node = stack.top();

            // If node has a left child, push it to stack & break it's link to parent (node)
            if(node->left) {
                stack.push(node->left);
                node->left = nullptr;
                continue;   // Continue doing so, untill we reach leftest leaf node.
            }

            // When we have reached left leaf node, pop the stack top & make it part of solution
            node = stack.top();
            stack.pop();

            // If node has right child node, push it to stack & break it's link to parent (node)
            if(node->right) {
                stack.push(node->right);
                node->right = nullptr;
                continue;   // Added just for symmetry
            }
        }

        return r;
    }
};

int main() {
    Solution solution;
    TreeNode *root;

    // TODO: Implement Binary Tree

    // solution.inorderTraversal(root);

    return 0;
}