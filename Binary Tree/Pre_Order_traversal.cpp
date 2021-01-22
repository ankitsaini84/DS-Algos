/**
 * PRE ORDER TRAVERSAL - Root - Left - Right
 * 
 * Given the root of a binary tree, return the preorder 
 * traversal of its nodes' values.
 * 
 * EXAMPLE:
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
 * 
 * CONSTRAINTS:
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * LINK: https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/928/
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
    std::vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return r;   // break condition

        r.push_back(root->val);         // Read Root
        preorderTraversal(root->left);  // Traverse Left
        preorderTraversal(root->right); // Traverse Right

        return r;                       // return final solution
    }

    // Stack Implementation
    std::vector<int> preorderTraversal(TreeNode* root) {
        // Prepare a stack
        std::stack<TreeNode*> stack {};

        // break if there's no root ~ no tree.
        if(root == nullptr) return r;

        TreeNode *node {nullptr};
        stack.push(root);

        // Iterate till we have no elements in the stack
        while(!stack.empty()) {

            // Pop top element from the stack & push it's value to the solution
            // Pre-Order -> read Root first.
            node = stack.top();
            stack.pop();
            r.push_back(node->val);

            // Since, stack unwinds in reverse order, push Right child first
            if(node->right) {
                stack.push(node->right);
            }   // & then, push Left child.
            if(node->left) {
                stack.push(node->left);
            }
            // IMP: When Pop-Top is called, 'Left' child will be picked first.
        }

        // return solution
        return r;
    }
};

int main() {
    Solution s;
    TreeNode *root;

    // TODO: Create tree here!

    // s.preorderTraversal(root);

    return 0;
}