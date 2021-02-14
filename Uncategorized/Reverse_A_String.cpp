/**
 * Write a function that reverses a string. The input string is given as an array of 
 * characters char[].
 * 
 * Do not allocate extra space for another array, you must do this by modifying the 
 * input array in-place with O(1) extra memory.
 * 
 * You may assume all the characters consist of printable ascii characters.
 */
#include <iostream>
#include <vector>

class Solution {
    char t {};
    void helper(std::vector<char>& s, const int i, const int j) {
        if(i >= j) return;  // iterate till i & j meet halfway
        
        // swap
        t = s[i];
        s[i] = s[j];
        s[j] = t;

        helper(s, i+1, j-1);    // recurse
    }
public:
    void reverseString(std::vector<char>& s) {
        helper(s, 0, static_cast<int>(s.size()-1));              
    }
};

int main() {
    Solution s;
    std::vector<char> str {'A', 'n', 'k', 'i', 't', 'S', 'a', 'i', 'n', 'i'};
    s.reverseString(str);
    std::cout << "Reversed String : ";
    for(auto c : str) {
        std::cout << c;
    }

    return 0;
}