/**
 * A linked list of length n is given such that each node contains an additional 
 * random pointer, which could point to any node in the list, or null.
 * 
 * Construct a deep copy of the list. The deep copy should consist of exactly n brand 
 * new nodes, where each new node has its value set to the value of its corresponding 
 * original node. Both the next and random pointer of the new nodes should point to 
 * new nodes in the copied list such that the pointers in the original list and copied 
 * list represent the same list state. None of the pointers in the new list should 
 * point to nodes in the original list.
 * 
 * For example, if there are two nodes X and Y in the original list, where 
 * X.random --> Y, then for the corresponding two nodes x and y in the copied list, 
 * x.random --> y.
 * 
 * Return the head of the copied linked list.
 * 
 * The linked list is represented in the input/output as a list of n nodes. Each 
 * node is represented as a pair of [val, random_index] where:
 * 
 * + val: an integer representing Node.val\
 * + random_index: the index of the node (range from 0 to n-1) that the random pointer
 *   points to, or null if it does not point to any node.
 * 
 * Your code will only be given the head of the original linked list.
 * 
 * EXAMPLE:
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 */
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

/**
 * Algo ~  https://leetcode.com/problems/copy-list-with-random-pointer/discuss/1059181/C%2B%2B-or-Three-Pass-or-O(n)-0ms-Beats-100-or-Explanation-(with-example)
 */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        
        // Step 1: Creating New Nodes in LL.
        // If initially, LL is [A -> B -> C -> D]
        // Make it -> [A -> A' -> B -> B' -> C -> C' -> D -> D']
        // Where, A' B', C', D' are new nodes.
        Node* crawl {head};
        while(crawl) {
            Node* newNode {new Node(crawl->val)};
            newNode->next = crawl->next;
            crawl->next = newNode;
            crawl = newNode->next;
        }
        
        // Step 2: Copying the random Pointers
        // Again iterate the link list and alternatively copy the old node's random 
        // pointer (if exists) to the new node's random pointer as shown below 
        // node->next->random=node->random->next
        crawl = head;
        while(crawl) {
            if(crawl->next) {
                crawl->next->random = crawl->random == nullptr ? nullptr : crawl->random->next;
                crawl = crawl->next->next;
            }
        }
        
        // Step 3: Restoring Old Links
        // Break the links b/w oldNodes & newNodes & restore both LLs to their glory.
        Node* newHead {head->next};
        Node* tcrawl {head->next};
        crawl = head;
        while(crawl) {
            crawl->next = tcrawl->next;
            tcrawl->next = tcrawl->next == nullptr ? nullptr : tcrawl->next->next;
            crawl = crawl->next;
            tcrawl = tcrawl->next;
        }
        
        return newHead;
    }
};

int main() {
    return 0;
}