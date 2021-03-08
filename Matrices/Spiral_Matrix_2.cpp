/**
 * Given a positive integer n, generate an n x n matrix filled with elements from 
 * 1 to n^2 in spiral order.
 * 
 * EXAMPLE:
 * 1 -> 2 -> 3
 *           |
 * 8 -> 9    4
 * |         |
 * 7 <- 6 <- 5
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 * 
 * CONSTRAINTS:
 * 1 <= n <= 20
 */

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n,std::vector<int>(n,0));
        int x {0};
        int y {0};
        int i {0};
        int R {n};
        int C {n};
        int cnt {1};
        while(R-i) {
            while(y < C - i) {
                // cout << x << "," << y << " :" << cnt << "\n";
                matrix[x][y] = cnt++;
                ++y;
            }
            --y;
            ++x;
            
            while(x < R - i) {
                // cout << x << "," << y << " :" << cnt << "\n";
                matrix[x][y] = cnt++;
                ++x;
            }
            --x;
            --y;
            
            while(y >= i) {
                // cout << x << "," << y << " :" << cnt << "\n";
                matrix[x][y] = cnt++;
                --y;
            }
            ++y;
            --x;
            
            while(x > i) {
                // cout << x << "," << y << " :" << cnt << "\n";
                matrix[x][y] = cnt++;
                --x;
            }
            ++x;
            ++y;
            ++i;
            
        }
        return matrix;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix {s.generateMatrix(3)};
    for(auto row : matrix) {
        for(auto col : row) {
            std::cout << col << " ";
        }
        std::cout << "\n";
    }
    return 0;
}