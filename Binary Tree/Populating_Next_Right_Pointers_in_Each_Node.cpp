/**
 * You are given a binary tree with following definition:
 * struct Node {
 *  int val;
 *  Node *left;
 *  Node *right;
 *  Node *next;
 * }
 * 
 * Populate each next pointer to point to its next right node. If there is no next 
 * right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 * 
 * EXAMPLE:
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [1,#,2,3,#,4,5,6,7,#]
 *      1               1
 *     / \            /   \
 *    2   3          2----->3
 *   / \ / \       /  \    /  \
 *  4  5 6  7     4--->5->6--->7
 *  (Figure A)      (Figure B)
 * 
 * Explanation: Given the above perfect binary tree (Figure A), your function should 
 * populate each next pointer to point to its next right node, just like in Figure B. 
 * The serialized output is in level order as connected by the next pointers, with '#' 
 * signifying the end of each level.
 * 
 * CONSTRAINTS:
 * The number of nodes in the given tree is less than 4096.
 * -1000 <= node.val <= 1000.
 */
#include <iostream>
#include <queue>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;

        std::queue<Node*> queue {};
        queue.push(root);
        Node* node {nullptr};
        int size {static_cast<int>(queue.size())};

        // Iterate till the queue is not empty
        while(!queue.empty()) {
            // Take out the topmost element from the queue
            node = queue.front();
            queue.pop();
            --size;

            // Add node's left & right nodes.
            if(node->left) {
                queue.push(node->left);
            }
            if(node->right) {
                queue.push(node->right);
            }

            // If we have reached the end of the size (of the level) 
            // - update size for new level
            // Else, join the node to its successor in queue.
            if(size == 0) {
                size = static_cast<int>(queue.size());
            } else {
                node->next = queue.front();
            }
        }
        // Return Tree
        return root;
    }
};

int main() {

    return 0;
}