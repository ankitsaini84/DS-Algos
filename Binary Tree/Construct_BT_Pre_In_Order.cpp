/**
 * Construct Binary Tree from Inorder and Preorder Traversal
 * 
 * EXAMPLE:
 * inorder = [9,3,15,20,7]
 * preorder = [3,9,20,15,7]
 */
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Algo ~
 * Considering this input..
 * inorder: [9, 3, 15, 20, 7]
 * pretorder: [3, 9, 20, 15, 7]
 * 1. Use the first element of preorder, 3, as root.
 * 2. Search it in inorder.
 * 3. Split inorder by it, here into [9] and [15, 20, 7].
 * 4. Split the rest of preorder into two parts as large as the inorder parts, 
 *    here into [9] & [20, 15, 7].
 * 5. Use preorder = [20, 15, 7] and inorder = [15, 20, 7] to add the left subtree.
 * 6. Use preorder =[9] & inorder = [9] to add the right subtree.
 */
class Solution {
    int r {0};  // For preorder traversal, 1st element is the Root of the tree.
    
    TreeNode* helper(std::vector<int>& inorder, int s, int e, std::vector<int>& preorder) {
        if(s > e) return nullptr;
        
        int root {preorder[r++]};
        
        int i {s};
        for( ; i <= e; ++i) {
            if(inorder[i] == root) {
                break;
            }
        }
        
        TreeNode* node = new TreeNode(root);
        node->left = helper(inorder, s, i-1, preorder);
        node->right = helper(inorder, i+1, e, preorder);
        return node;
    }
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        return helper(inorder, 0, static_cast<int>(inorder.size()) - 1, preorder);
    }
};