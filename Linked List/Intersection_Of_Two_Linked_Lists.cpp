/**
 * Write a program to find the node at which the intersection of two singly linked 
 * lists begins.
 * 
 * EXAMPLE:
 * A:         a1 -> a2
 *                     \
 *                      c1 -> c2 -> c3
 *                     /
 * B:   b1 -> b2 -> b3
 * 
 * begin to intersect @ node c1.
 * 
 * NOTE:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Each value on each linked list is in the range [1, 10^9].
 * Your code should preferably run in O(n) time and use only O(1) memory.
 */

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // #1. Find the length of both the lists.
        ListNode* curr {headA};
        int lenA {0};
        while(curr) {
            ++lenA;
            curr = curr->next;
        }
        
        int lenB {0};
        curr = headB;
        while(curr) {
            ++lenB;
            curr = curr->next;
        }
        
        // #2. Find difference between lengths of both the lists.
        ListNode* curr2 {nullptr};
        int diff {0};
        if(lenA > lenB) {
            curr = headA;
            curr2 = headB;
            diff = lenA - lenB;
        } else {
            curr = headB;
            curr2 = headA;
            diff = lenB - lenA;
        }
        
        // #3. Iterate longer list till it's start point reaches the same point from 
        // where both lists have same length.
        while(diff) {
            --diff;
            curr = curr->next;
        }
        
        // #4. Now, just iterate both lists till they either reach EOL or the 
        // intersection point.
        while(curr && curr2) {
            if(curr == curr2) {
                return curr;
            }
            curr = curr->next;
            curr2 = curr2->next;
        }
        
        // #5. Return nullptr, if they reach EOL - no point of intersection.
        return nullptr;
    }
};

int main() {
    return 0;
}