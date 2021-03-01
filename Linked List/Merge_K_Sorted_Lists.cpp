/**
 * 
 */

#include <iostream>
#include <vector>
#include <queue>    // priority_queue

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Algo ~
 * 1. Traverse & Insert 1st elements of all k lists in the priority queue.
 *    NOTE: Priority Queue always maintains the smallest element at top.
 * 2. Fetch top-most element (smallest) from pqueue.
 * 3. Go to the kth list (to which the fetched element belonged to) & add the element 
 *    to the ANSWER.
 * 4. Make List-head of kth list point to the next element in the list.
 * 5. Push the new List-head to pqueue.
 * 6. Keep repeating (from 2.) untill pqueue is empty.
 * 7. Return ANSWER.
 */
class Solution {
    class comparison {
        public:
        // comparison functor
        bool operator() (const std::pair<int,int> &lhs, const std::pair<int,int> &rhs) const {
            return lhs.first > rhs.first;
        }
    };
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comparison> pq;
        std::pair<int, int> p;

        // push 1st elements of all lists to the pqueue
        for(int k {0}; k < static_cast<int>(lists.size()); ++k) {
            if(lists[k]) {
                p.first = lists[k]->val;
                p.second = k;
                pq.push(p);
            }
        }
        
        ListNode* answer {nullptr};
        ListNode* tail {nullptr};
        int k {};
        while(!pq.empty()) {
            p = pq.top();
            pq.pop();
            k = p.second;
            // make head of kth list - part of answer
            if(answer == nullptr) {
                answer = lists[k];
            } else {
                tail->next = lists[k];
            }
            tail = lists[k];
            
            // disjoint link from kth list
            lists[k] = lists[k]->next;
            
            // push the list-head to pqueue
            if(lists[k]) {
                p.first = lists[k]->val;
                // p.second is already k
                pq.push(p);
            }
        }
        return answer;
    }
};

int main() {
    return 0;
}