#include <iostream>
/**
 * Merge two sorted linked lists and return it as a sorted list. The list should be 
 * made by splicing together the nodes of the first two lists.
 * 
 * CONSTRAINTS:
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both l1 and l2 are sorted in non-decreasing order.
 * 
 * EXAMPLE:
 * Input: l1 = [1,2,4], l2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
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

void add(ListNode** head, ListNode** tail, int val) {
    ListNode* newNode = new ListNode(val);

    if(*head == nullptr) {
        *head = newNode;
    } else {
        (*tail)->next = newNode;
    }
    *tail = newNode;
}

void print(ListNode* head) {
    ListNode* c {head};
    while(c) {
        std::cout << c->val << " -> ";
        c = c->next;
    }
    std::cout << "nullptr\n";
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* c1 {l1};
        ListNode* c2 {l2};
        ListNode* min {nullptr};
        ListNode* answer {nullptr};
        ListNode* tail {nullptr};
        
        while(c1 || c2) {
            if((c1 ? c1->val : INT_MAX) < (c2 ? c2->val : INT_MAX)) {
                min = c1;
                c1 = c1->next;
            } else {
                min = c2;
                c2 = c2->next;
            }
            
            if(answer == nullptr) {
                answer = min;
            } else {
                tail->next = min;
            }
            tail = min;            
        }
        return answer;
    }
};

int main() {
    ListNode* list1 {nullptr};
    ListNode* list2 {nullptr};
    ListNode* tail {nullptr};

    add(&list1, &tail, 1);
    add(&list1, &tail, 2);
    add(&list1, &tail, 4);
    print(list1);
    
    tail = nullptr;
    add(&list2, &tail, 1);
    add(&list2, &tail, 3);
    add(&list2, &tail, 4);
    print(list2);

    Solution s;
    ListNode* answer = s.mergeTwoLists(list1, list2);
    print(answer);

    return 0;
}