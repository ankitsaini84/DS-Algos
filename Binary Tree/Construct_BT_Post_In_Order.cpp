/**
 * Construct Binary Tree from Inorder and Postorder Traversal
 * 
 * EXAMPLE:
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
 * postorder: [9, 15, 7, 20, 3]
 * 1. Use the last element of postorder, 3, as root.
 * 2. Search it in inorder.
 * 3. Split inorder by it, here into [9] and [15, 20, 7].
 * 4. Split the rest of postorder into two parts as large as the inorder parts, 
 *    here into [9] & [15, 7, 20].
 * 5. Use postorder = [15, 7, 20] and inorder = [15, 20, 7] to add the right subtree.
 * 6. Use postorder =[9] & inorder = [9] to add the left subtree.
 */
class Solution {
    int r {0};
    TreeNode* helper(std::vector<int>& inorder, int s, int e, std::vector<int>& postorder) {
        if(s > e) return nullptr;
              
        // find root from postorder
        int root {postorder[r--]};
        // search for root value in inroder
        // IMP: A mojor improvement can be to insert all elements of inorder tree 
        // into a hashmap & then use map.find() method to find the index.
        // This aproach will save on time to find 'i'.
        int i {s};
        for( ; i <= e; ++i) {
            if(inorder[i] == root) {
                break;
            }
        }

        // Displays tree for this iteration
        // for(int a {s}; a < i; ++a) {
        //     std::cout << inorder[a] << ' ';
        // }
        // std::cout << "| " << inorder[i] << " | ";
        // for(int a {i+1}; a <= e; ++a) {
        //     std::cout << inorder[a] << ' ';
        // }
        // std::cout << '\n';

        // Create node & return it.
        TreeNode* node = new TreeNode(root);
        // Get Right Child
        node->right = helper(inorder, i+1, e, postorder);
        // Get Left Child
        node->left = helper(inorder, s, i-1, postorder);
        
        return node;
    }
    public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        r = static_cast<int>(postorder.size()-1);
        return helper(inorder, 0, static_cast<int>(inorder.size())-1, postorder);
    }
};

int main() {
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    std::vector<int> postorder = {9, 15, 7, 20, 3};

    Solution s;
    TreeNode* root;
    root = s.buildTree(inorder, postorder);
    return 0;
}
