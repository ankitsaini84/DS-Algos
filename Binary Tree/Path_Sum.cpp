/**
 * Given the root of a binary tree and an integer targetSum, return true if the tree
 * has a root-to-leaf path such that adding up all the values along the path equals
 * targetSum.
 * 
 * EXAMPLE:
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * Output: true
 * 
 * EXAMPLE:
 * Input: root = [1,2,3], targetSum = 5
 * Output: false
 * 
 * EXAMPLE:
 * Input: root = [1,2], targetSum = 0
 * Output: false
 * 
 * CONSTRAINTS:
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
 * 
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

    // Recursive Solution
    bool hasPathSum(TreeNode* node, int targetSum, int prevSum) {
        if(!node) return false;

        // When @ leaf node, check if sum equals targetSum.
        // If yes, return 'true'
        if((!node->left && !node->right) &&
        (prevSum + node->val == targetSum)) {
            return true;
        }

        // Traverse the child nodes & if either of the paths have already returned 'true', keep returning it.
        if(hasPathSum(node->left, targetSum, prevSum + node->val)) return true;
        if(hasPathSum(node->right, targetSum, prevSum + node->val)) return true;

        // Return 
        return false;
    }

    // TODO: Iterative Solution
    /*bool hasPathSum(TreeNode* node, int targetSum) {
        int sum {0};
        TreeNode* node {nullptr};
        std::stack<int> stack {};
        stack.push(node);
        while(!stack.empty()) {
            node = stack.top();
            stack.pop();

            if(!node->left && !node->right &&
            targetSum - node->val == 0) {
                return true;
            }

            if(node->left) {
                stack.push(node->left);
            }
            if(node->right) {
                stack.push(node->right);
            }
        }
    }*/

    bool hasPathSum(TreeNode* root, int targetSum) {
       return hasPathSum(root, targetSum, 0);
    }
};

int main() {
    return 0;
}