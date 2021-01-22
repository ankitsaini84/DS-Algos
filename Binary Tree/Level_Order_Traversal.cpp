/**
 * LEVEL ORDER TRAVERSAL - Level-wise Traversal
 * 
 * Given a binary tree, return the level order traversal 
 * of its nodes' values. (ie, from left to right, level by level).
 * 
 * EXAMPLE:
 * Input: [3,9,20,null,null,15,7]
 * Output: [ [3], [9,20], [15,7] ]
 */

#include <iostream>
#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> r {};

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return r;

        // Queue to insert the traversed nodes
        std::queue<TreeNode*> queue {};
        TreeNode* node {nullptr};
        // Temporary vector to hold nodes in a level
        std::vector<int> t {};

        queue.push(root);
        // Queue temp. size ~ depicts elements inserted till we reach next level.
        int size {static_cast<int>(queue.size())};

        while(!queue.empty()) { // Iterate till queue is empty

            // Pop Front node, add it to temp. vector & decrease the queue temp size.
            node = queue.front();
            queue.pop();
            --size;
            t.push_back(node->val);
            
            // Add left & right nodes (if any) to queue.
            if(node->left) {
                queue.push(node->left);
            }
            if(node->right) {
                queue.push(node->right);
            }

            // If all the nodes in queue have been exhausted for previous level -
            // push temp. vector to resultant vector &
            // get new size of the queue ~ since, all added elements are present in
            // the queue, new size will be equal to elements added for this level.
            if(size == 0) {
                r.push_back(t);
                t.clear();
                size = static_cast<int>(queue.size());
            }
        }

        return r;
    }
};

int main() {
    
    return 0;
}