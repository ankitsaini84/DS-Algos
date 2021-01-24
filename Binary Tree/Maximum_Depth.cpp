/**
 * Given the root of a binary tree, return its maximum depth.
 * A binary tree's maximum depth is the number of nodes along the longest path from
 * the root node down to the farthest leaf node.
 * 
 * EXAMPLE:
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 3
 * 
 * CONSTRAINTS:
 * The number of nodes in the tree is in the range [0, 104].
 * -100 <= Node.val <= 100
 * 
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
 
class Solution {
    int max(const int a, const int b) {
        return a > b ? a : b;
    }
    // Bottom-to-Top Approach - Post-Order Traversal
    // Traverse to till leaf node.
    // When @ leaf node -> Start depth as 0.
    // When @ parent node, find the greater depth from it's children & propogate
    // the depth+1 to top.
    int bottomUp(TreeNode* node) {
        if(!node) return 0; // return depth '0' when @ leaf node

        // Traverse to left & right of the tree & find out their respective depths
        // Return, which ever is more + 1.
        int leftDepth {bottomUp(node->left)};
        int rightDepth {bottomUp(node->right)};
        return max(leftDepth, rightDepth) + 1;
    }

    // Top-to-Bottom Approach - Pre-Order Traversal
    // When @ a node, find it's depth right there, and pass on this depth to
    // the children and let them calculate their depth & update answer.
    int answer {0};
    int topDown(TreeNode* node, int depth) {
        // When @ leaf node, update the answer
        if(!node->left && !node->right) {
            if(depth > answer) {
                answer = depth;
            }
        }

        // Keep propogating the depth to children
        if(node->left) topDown(node->left, depth + 1);
        if(node->right) topDown(node->right, depth + 1);
        
        // return final answer
        return answer + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        return bottomUp(root);
        return topDown(root, 0);
    }
};

int main() {

    return 0;
}
