/**
 * POST ORDER TRAVERSAL - Left - Right - Root
 * 
 * IMP: It is worth noting that when you delete nodes in a tree, 
 * deletion process will be in post-order. That is to say, when 
 * you delete a node, you will delete its left child and its 
 * right child before you delete the node itself.
 * 
 * IMP: Also, post-order is widely use in mathematical 
 * expression. 
 * 
 * 
 * Given the root of a binary tree, return the inorder 
 * traversal of its nodes' values.
 * 
 * EXAMPLE:
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
 * 
 * CONSTRAINTS:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * LINK: https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/930/
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
    std::vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return r;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        r.push_back(root->val);

        return r;
    }

    // Iterative Solution using Stack
    std::vector<int> postorderTraversal(TreeNode* root) {    
        if(root == nullptr) return r;

        std::stack<TreeNode*> stack {};
        TreeNode* node {nullptr};

        stack.push(root);
        while(!stack.empty()) {
            node = stack.top();

            if(node->left) {
                stack.push(node->left);
                node->left = nullptr;
                continue;
            }

            if(node->right) {
                stack.push(node->right);
                node->right = nullptr;
                continue;
            }

            // node = stack.top();
            stack.pop();
            r.push_back(node->val);
        }

        return r;
    }
};

int main() {
    Solution solution;
    TreeNode *root;

    // TODO: Implement Binary Tree

    // solution.postorderTraversal(root);

    return 0;
}