/**
 * Given an integer n, return the number of strings of length n
 * that consist only of vowels (a, e, i, o, u) and are
 * lexicographically sorted.
 * 
 * A string s is lexicographically sorted if for all valid i, 
 * s[i] is the same as or comes before s[i+1] in the alphabet.
 */

#include <iostream>

class Solution {
public:
    int count(int p, int n) {
        if(n == 0) return 1;
        int sum {0};

        for(int i = p; i < 5; ++i) {
            sum += count(i, n-1);
        }
        return sum;
    }

    int countVowelStrings(int n) {
        return count(0, n);
    }
};

int main() {
    Solution s;
    std::cout << s.countVowelStrings(2) << '\n';

    return 0;
}