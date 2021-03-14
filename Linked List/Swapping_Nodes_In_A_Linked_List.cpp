/**
 * You are given the head of a linked list, and an integer k.\
 * Return the head of the linked list after swapping the values of the kth node from the 
 * beginning and the kth node from the end (the list is 1-indexed).
 * 
 * EXAMPLE:
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [1,4,3,2,5]
 * 
 * CONSTRAINTS:
 * The number of nodes in the list is n.
 * 1 <= k <= n <= 10^5
 * 0 <= Node.val <= 100
 */

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* add(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val, head);
    head = newNode;
    return head;
}

/**
 * ALGORITHM:
 * 1. Start crawling from beginning until we reach k.
 * 2. Once @ k, mark this as location as 1st. (found from left)
 * 3. To find kth location from right -- start iterating another pointer from head
 *    till the crawler reaches end-of-list, & mark the final location as 2nd.
 *    This distance will be equivalent to k from right.
 * 4. Swap values of 1st & 2nd.
 * 5. Return head.
 */

/**
 * EXPLANATION:
 * 1 2 3 4 5 6 7 8 9 10
 * . . . . . . . . . .
 * |- - -| <--- When reached @ k = 4, 1st location marked from left
 *       ^
 *       1st
 * To find kth location right --
 * use this as a scale. Keep shifting this scale to right.
 * when this scale reaches the end -- leftmost side of the scale
 * will be @ the kth location fro right.
 * 
 * 1 2 3 4 5 6 7 8 9 10
 * . . . . . | - - - | <--- scale reaches end of list
 *       ^   ^
 *       1st 2nd
 */

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        int i {0};
        ListNode* crawl {head};
        ListNode* first {nullptr};
        ListNode* second {head};
        
        while(crawl) {
            ++i;
            if(i == k) {
                first = crawl;
            } else if(i > k) {
                second = second->next;
            }
            crawl = crawl->next;
        }
        
        int t = first->val;
        first->val = second->val;
        second->val = t;
    
        return head;
    }
};

int main() {
    Solution s;
    ListNode* list {nullptr};

    std::cout << "nullptr\n";
    list = add(list, 5);
    list = add(list, 4);
    list = add(list, 3);
    list = add(list, 2);
    list = add(list, 1);
    
    ListNode* crawl {list};
    while(crawl) {
        std::cout << crawl->val << "->";
        crawl = crawl->next;
    }
    std::cout << "nullptr\n";
    
    list = s.swapNodes(list, 2);
    
    crawl = list;
    while(crawl) {
        std::cout << crawl->val << "->";
        crawl = crawl->next;
    }
    std::cout << "nullptr\n";

    return 0;
}