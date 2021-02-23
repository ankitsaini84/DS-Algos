/**
 * Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it 
 * in-place.
 * 
 * EXAMPLE:
 * 1 1 1      1 0 1
 * 1 0 1  =>  0 0 0
 * 1 1 1      1 0 1
 * 
 * EXAMPLE:
 * 0 1 2 0      0 0 0 0
 * 3 4 5 2  =>  0 4 5 0
 * 1 3 1 5      0 3 1 0
 * 
 * CONSTRAINTS:
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 */

#include <iostream>
#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int rows {static_cast<int>(matrix.size())};
        int cols {static_cast<int>(matrix[0].size())};
        int x {0};
        int y {0};
        int mark1stRowFor0s { false };
        int mark1stColFor0s { false };
        
        // first pass
        // Use 0th Row & 0th Column for storing the reference values for respective 
        // index i.e. If we encounter a 0 @ 0th row or column for a particular index in 
        // next pass, we mark that index as 0.
        while(x < rows) {
            y = 0;
            while(y < cols) {
                if(matrix[x][y] == 0) {
                    // Also, since we using 0th row & column for stroing reference values for other indexes, we mark the following flags if they also need to be marked w/ 0s later (i.e. if they encounter any 0s).
                    if(y == 0) mark1stColFor0s = true;
                    if(x == 0) mark1stRowFor0s = true;

                    // mark 0th row & column for future reference.
                    matrix[0][y] = 0;
                    matrix[x][0] = 0;
                }
                ++y;
            }
            ++x;
        }
        
        // second pass
        // In this pass, if respective 0th row or column is marked, it menas that this 
        // row/column has to be marked w/ 0s.
        x = 1;
        y = 1;
        while(x < rows) {
            y = 1;
            while(y < cols) {
                if(matrix[0][y] == 0 || matrix[x][0] == 0) {
                    matrix[x][y] = 0;
                }
                ++y;
            }
            ++x;
        }
        
        // Earlier, we used flag to mark - if 0th column needs to be marked w/ 0s.
        if(mark1stRowFor0s) {
            x = 0;
            y = 0;
            while(y < cols) {
                matrix[x][y] = 0;
                ++y;
            }
        }
        
        // Aslo, we used flag to mark - if 0th row needs to be marked w/ 0s.
        if(mark1stColFor0s) {
            x = 0;
            y = 0;
            while(x < rows) {
                matrix[x][y] = 0;
                ++x;
            }
        }
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    std::cout << "Answer : \n";
    s.setZeroes(matrix);
    for(std::vector<int> r : matrix) {
        for(int c : r) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
    return 0;
}