/**
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 * EXAMPLE:
 * 1 -> 2 -> 3
 *           |
 * 4 -> 5    6
 * |         |
 * 7 <- 8 <- 9
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * CONSTRAINTS:
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 */

#include <iostream>
#include <vector>

class Solution {
    int visited[100][100] {};
    int tc {0};
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        ++tc;
        std::vector<int> result;
        int R {static_cast<int>(matrix.size())};
        int C {static_cast<int>(matrix[0].size())};
        int x {0};
        int y {0};
        int direction {0};
        bool flag {false};
        while(1) {
            if(direction == 0) { // right
                if(y < C && visited[x][y] != tc) {
                    // cout << matrix[x][y] << "R\n";
                    result.push_back(matrix[x][y]);
                    visited[x][y] = tc;
                    ++y;
                    flag = false;
                }
                else {
                    // if I couldn't use it, no one can - break the loop
                    if(flag == true) break;
                    direction++;
                    --y;
                    ++x;
                }
            } else if(direction == 1) { // down
                if(x < R && visited[x][y] != tc) {
                    // cout << matrix[x][y] << "D\n";
                    result.push_back(matrix[x][y]);
                    visited[x][y] = tc;
                    ++x;
                }
                else {
                    direction++;
                    --x;
                    --y;
                }
            } else if(direction == 2) { // left
                if(y >= 0 && visited[x][y] != tc) {
                    // cout << matrix[x][y] << "L\n";
                    result.push_back(matrix[x][y]);
                    visited[x][y] = tc;
                    --y;
                }
                else {
                    direction++;
                    ++y;
                    --x;
                }
            } else if(direction == 3) { // up
                if(x >= 0 && visited[x][y] != tc) {
                    // cout << matrix[x][y] << "U\n";
                    result.push_back(matrix[x][y]);
                    visited[x][y] = tc;
                    --x;
                }
                else {
                    flag = true;
                    // if 'right' does not use it, then no one will - break the loop
                    direction = 0;  // reset direction to 'right'
                    ++x;
                    ++y;
                }
            }
        }
        return result;
    }
};

int main() {
    std::vector<std::vector<int>> v {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    Solution s;
    std::vector<int> spiral = s.spiralOrder(v);
    for(int i : spiral) {
        std::cout << i << " -> ";
    }
    std::cout << "finish\n";
    return 0;
}