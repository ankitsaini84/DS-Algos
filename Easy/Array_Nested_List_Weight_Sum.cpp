/**
 * You are given a nested list of integers nestedList. 
 * Each element is either an integer or a list whose elements may also be integers or other lists.
 * 
 * The depth of an integer is the number of lists that it is inside of. 
 * For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth.
 * 
 * Return the sum of each integer in nestedList multiplied by its depth.
 * 
 * Example:
 * Input: nestedList = [[1,1],2,[1,1]]
 * Output: 10
 * Explanation: Four 1's at depth 2, one 2 at depth 1. 1*2 + 1*2 + 2*1 + 1*2 + 1*2 = 10.
 * 
 * Constraints:
 * 1 <= nestedList.length <= 50
 * The values of the integers in the nested list is in the range [-100, 100].
 * The maximum depth of any integer is less than or equal to 50.
 */

#include <iostream>
#include <vector>
#include <queue>

 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
   public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};

class Solution {
public:
    // Solution by DFS (recursion)
    int dfs(const std::vector<NestedInteger>& list, const int d) {
        int s{0};
        for(const auto& i : list) {
            if(i.isInteger()) {
                s += d * i.getInteger();
            } else {
                s += dfs(i.getList(), d+1);
            }
        }
        return s;
    }
    
    // Solution by BFS (Queue)
    int bfs(const std::vector<NestedInteger>& list) {
        std::queue<NestedInteger> q;

        // Add all elements to queue
        for(const NestedInteger& i : list) {
            q.push(i);
        }

        int sum     {0};
        int depth   {1};
        int size    {static_cast<int>(q.size())};
        int i       {1};
        NestedInteger e;

        // Iterate till queue is NOT empty
        while(!q.empty()) {
            // To keep track of depth, till the previous elements are not traversed,
            // keep the depth same. As soon as previously added elements are done
            // traversing - update 'size' & 'depth'
            if(i > size) {
                ++depth;
                size = static_cast<int>(q.size());
                i = 1;
            }
            
            e = q.front();
            q.pop();
            if(e.isInteger()) {
                sum += depth * e.getInteger();
            } else {
                for(const NestedInteger& i : e.getList()) {
                    q.push(i);
                }
            }
            ++i;
        }
        return sum;
    }

    int depthSum(std::vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
        return bfs(nestedList);
    }
};

int main() {
    // NOTE: Can't execute this solution as NestedInteger class is missing.
    return 0;
}