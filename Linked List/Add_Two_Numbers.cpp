/**
 * You are given two non-empty linked lists representing two non-negative integers. The 
 * digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 
 * itself.
 * 
 * CONSTRAINTS:
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have leading zeros.
 * 
 * EXAMPLE:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * 
 * EXAMPLE:
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* c1 {l1};
        ListNode* c2 {l2};
        ListNode* prev {nullptr};
        int t1, t2;
        int carryOver {0};
        ListNode* answer;
        
        while(c1 || c2) {
            t1 = (c1 ? c1->val : 0) + (c2 ? c2->val : 0) + carryOver;
            carryOver = 0;
            
            if(t1 > 9) {
                t2 = t1;
                carryOver = t1 / 10;
                t1 = t2 % 10;
            }
            
            if(c1) {
                c1->val = t1;
                prev = c1;
                c1 = c1->next;
                answer = l1;
            }
            if(c2) {
                c2->val = t1;
                prev = c2;
                c2 = c2->next;
                answer = l2;
            }
        }

        if(carryOver) {
            prev->next = new ListNode(carryOver);
        }
        return answer;
    }
};

int main() {
    return 0;
}