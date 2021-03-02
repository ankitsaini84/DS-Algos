/**
 * Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of 
 * islands.
 * An island is surrounded by water and is formed by connecting adjacent lands 
 * horizontally or vertically. You may assume all four edges of the grid are all 
 * surrounded by water.
 * 
 * CONSTRAINTS:
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 */

#include <iostream>
#include <vector>

constexpr char VISITED {'2'};
constexpr char WATER {'0'};
constexpr char LAND {'1'};

class Solution {
    int rows;
    int columns;

    // BFS..
    void markIslandVisited(std::vector<std::vector<char>>& grid, const int i, const int j) {
        if(i < 0 || j < 0 || i >= rows || j >= columns) return;
        if(grid[i][j] == VISITED || grid[i][j] == WATER) return;
        
        grid[i][j] = VISITED;
        
        markIslandVisited(grid, i+1, j);
        markIslandVisited(grid, i-1, j);
        markIslandVisited(grid, i, j+1);
        markIslandVisited(grid, i, j-1);
    }
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        rows  = static_cast<int>(grid.size());
        columns = static_cast<int>(grid[0].size());
        
        int islandsFound {0};
        for(int i {0}; i < rows; ++i) {
            for(int j {0}; j < columns; ++j) {
                if(grid[i][j] == LAND) {
                    // mark whole island as visited
                    markIslandVisited(grid, i,j);
                    // increment number of islands visited
                    ++islandsFound;
                }
            }
        }
        
        return islandsFound;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> v {
        {'1', '1', '0', '0', '0'}, 
        {'1', '1', '0', '0', '0'}, 
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    std::cout << "Answer : " << s.numIslands(v);
    return 0;
}