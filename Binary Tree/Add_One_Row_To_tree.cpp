/**
 * Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

    Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
    cur's original left subtree should be the left subtree of the new left subtree root.
    cur's original right subtree should be the right subtree of the new right subtree root.
    If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.

*/

#include <iostream>
#include <vector>
#include <queue>

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
    std::vector<int> tree;
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // If we have to add node @ depth 1, insert 1 node above root.
        if(d == 1) {
            root = new TreeNode(v, root, nullptr);
            return root;
        }
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        int size {1};
        TreeNode* node {nullptr};
        std::vector<TreeNode*> nodes;
        int depth {1};
        
        while(!q.empty()) {
            node = q.front();
            q.pop();
            --size;
            nodes.push_back(node);
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
            if(size == 0) {
                if(++depth == d) {
                    // When @ desired depth -- add additional node
                    for(auto n : nodes) {
                            n->left = new TreeNode(v, n->left, nullptr);
                            n->right = new TreeNode(v, nullptr, n->right);
                    }
                    break;  // job done -- break
                }
                
                nodes.clear();  // clear all the nodes at previous level.
                size = static_cast<int>(q.size());
            }
        }
        return root;
    }
};

int main() {
    return 0;
}