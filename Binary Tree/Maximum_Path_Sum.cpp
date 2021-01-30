/**
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the 
 * sequence has an edge connecting them. A node can only appear in the sequence at most 
 * once. Note that the path does not need to pass through the root.
 * 
 * The path sum of a path is the sum of the node's values in the path.
 * 
 * Given the root of a binary tree, return the maximum path sum of any path.
 * 
 * EXAMPLE:
 * Input: root = [1,2,3]
 * Output: 6
 * Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
 * 
 * EXAMPLE:
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 * Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 * 
 * EXAMPLE:
 * Input: root = [-3]
 * Output: -3
 * 
 * CONSTRAINTS:
 * The number of nodes in the tree is in the range [1, 3 * 104].
 * -1000 <= Node.val <= 1000
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
    int maximum(const int a, const int b) {
        return a > b ? a : b;
    }
    
    int answer { -1001 };                  // Since, -1000 is the least possible -ive value
    
    int helper(TreeNode* root) {
        if(!root) return 0;                 // return 0 when @ leaf
        
        int left { helper(root->left) };    // evaluate left child's max sum
        int right { helper(root->right) };  // evaluate right child's max sum
        
        // If left or right child returns -ive sum - don't consider it.
        // - If both, left & right are -ive, only root will be considered.
        if(left < 0) left = 0;
        if(right < 0) right = 0;
        
        // Evaluate sum considering the root node & register it as asnswer if 
        // it's larger than previous answer.
        int sum {0};
        sum = left + right + root->val;
        answer = maximum(answer, sum);
        
        // We do not want to return the sum of left, right & root as when returning
        // from root, either left + root OR right + root can be part of the pathSum.
        // Thus, return whose pathSum is larger.
        return maximum(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return answer;
    }
};

int main() {
    return 0;
}