/**
 * You are given two non-empty linked lists representing two non-negative integers. The 
 * most significant digit comes first and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 
 * itself. 
 * 
 * EXAMPLE:
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
    ListNode* curr {head};

    while(curr) {
        std::cout << curr->val;
        curr = curr->next;
    }
}

/**
 * Algo ~
 * 1. Reverse both the numbers.
 * 2. Add them.
 * 3. Reverse the sum.
 */

class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* prev {nullptr};
        ListNode* curr {head};
        ListNode* next {nullptr};
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode* answer {nullptr};
        ListNode* prev {nullptr};
        int sum {0};
        int carryOver {0};
        ListNode* c1 {l1};
        ListNode* c2 {l2};
        
        while(c1 || c2) {
            sum = (c1 ? c1->val : 0) + (c2 ? c2->val : 0) + carryOver;
            carryOver = 0;
            
            if(sum > 9) {
                carryOver = sum / 10;
                sum = sum % 10;
            }
            
            if(c1) {
                c1->val = sum;
                answer = l1;
                prev = c1;
                c1 = c1->next;
            }
            if(c2) {
                c2->val = sum;
                answer = l2;
                prev = c2;
                c2 = c2->next;
            }
        }
        
        if(carryOver) {
            prev->next = new ListNode(carryOver);
        }
        return reverseList(answer);
    }
};

int main() {
    ListNode* num1 {nullptr};
    ListNode* num2 {nullptr};
    ListNode* tail {nullptr};

    add(&num1, &tail, 7);
    add(&num1, &tail, 2);
    add(&num1, &tail, 4);
    add(&num1, &tail, 3);
    print(num1);
    std::cout << " + ";
    tail = nullptr;
    add(&num2, &tail, 5);
    add(&num2, &tail, 6);
    add(&num2, &tail, 4);
    print(num2);
    std::cout << " = ";
    Solution s;
    ListNode* sum = s.addTwoNumbers(num1, num2);
    print(sum);
    return 0;
}