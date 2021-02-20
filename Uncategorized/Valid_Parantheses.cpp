/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * EXAMPLE:
 * Input: s = "()[]{}"
 * Output: true
 * 
 * EXAMPLE:
 * Input: s = "([)]"
 * Output: false
 * 
 * EXAMPLE:
 * Input: s = "{[]}"
 * Output: true
 * 
 * CONSTRAINTS:
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 */

#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stk;
        char c;
        int i {0};
        while((c = s[i++]) != '\0') {
            if(c == '{' || c == '(' || c == '[') {
                stk.push(c);
            } else if(!stk.empty()) {
                if(c == '}' && stk.top() == '{') {
                    stk.pop();
                } else if(c == ')' && stk.top() == '(') {
                    stk.pop();
                } else if(c == ']' && stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        if(stk.empty()) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    std::cout << s.isValid("{[]}");
    return 0;
}