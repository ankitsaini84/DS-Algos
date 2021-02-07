// Reverse a singly linked list.
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void add(ListNode** root, const int val) {
    // Add node @ the head.
    ListNode* newNode { new ListNode(val, *root) };
    *root = newNode;
}

void dissolve(ListNode** root) {
    ListNode* crawler {*root};
    ListNode* temp {nullptr};
    while(crawler) {
        temp = crawler;
        crawler = crawler->next;
        delete temp;
    }
}

void print(ListNode** root) {
    ListNode* crawler = *root;
    while(crawler) {
        std::cout << crawler->val << " -> ";
        crawler = crawler->next;
    }
    std::cout << "\n";
}

class Solution {
    ListNode* newhead {nullptr};
    ListNode* helper (ListNode* n) {
        if(!n) return nullptr;
        else if (!n->next) {
            newhead = n;
            return n;
        }

        ListNode* t { helper(n->next) };
        t->next = n;               
        n->next = nullptr;

        return n;
    }
public:
    ListNode* reverseList(ListNode* head) {
        helper(head);
        return newhead;
    }
};

int main() {
    Solution s;
    ListNode* root {nullptr};
    add(&root, 5);
    add(&root, 4);
    add(&root, 3);
    add(&root, 2);
    add(&root, 1);
    std::cout << "Original Linked List : ";
    print(&root);
    root = s.reverseList(root);
    std::cout << "Reversed Linked List : ";
    print(&root);
    dissolve(&root);
    return 0;
}