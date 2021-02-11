/**
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's 
 * (representing land) connected 4-directionally (horizontal or vertical.) You may 
 * assume all four edges of the grid are surrounded by water.
 * 
 * Count the number of distinct islands. An island is considered to be the same as 
 * another if and only if one island can be translated (and not rotated or reflected) 
 * to equal the other.
 * 
 * EXAMPLE:
 * 11000
 * 11000
 * 00011
 * 00011
 * 
 * Given the above grid map, return 1. 
 * 
 * EXAMPLE: 
 * 11011
 * 10000
 * 00001
 * 11011
 * 
 * Given the above grid map, return 3.
 * 
 * Notice that:
 * 1 1
 * 1
 * 
 * &
 * 
 * 1
 * 1 1
 * are considered different island shapes, because we do not consider
 * reflection/rotation. 
 * 
 * NOTE: The length of each dimension in the given grid does not exceed 50.
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>

constexpr int VISITED   {-1};
constexpr int WATER     {0};
constexpr int ISLAND    {1};

class Solution {
    std::map<std::string, char> uniqueIslands {};
    std::string currentIsland {""};
    int cols {0};
    int rows {0};
    
    void dfs(std::vector<std::vector<int>> &grid, const int x, const int y, const int dx, const int dy) {
        if(x < 0 || y < 0 || x >= rows || y >= cols) return;
        if(grid[x][y] == VISITED || grid[x][y] == WATER) return;
        
        grid[x][y] = VISITED;
        std::string localCoordinates = "(" + std::to_string(dx) + "," + std::to_string(dy) + "),";
        currentIsland += localCoordinates;

        dfs(grid, x, y+1, dx, dy+1); // right
        dfs(grid, x+1, y, dx+1, dy); // down
        dfs(grid, x, y-1, dx, dy-1); // left
        dfs(grid, x-1, y, dx-1, dy); // up
        
        return;
    }
public:
    int numDistinctIslands(std::vector<std::vector<int>>& grid) {
        rows = static_cast<int>(grid.size());
        cols = static_cast<int>(grid[0].size());
        
        // 1. From each node - if it's island, run dfs to get current island (string)
        // 2. Push the string to a map. Since, map only contains unique elements,
        //    all duplicated islands won't be a part of the map.
        // 3. Return total number of elements in the map as answer.
        for(int i {0}; i < rows; ++i) {
            for(int j {0}; j < cols; ++j) {
                if(grid[i][j] == ISLAND) {
                    currentIsland = "";
                    dfs(grid, i, j, 0, 0);
                    uniqueIslands.emplace(currentIsland, '\0');
                }
            }
        }
        return uniqueIslands.size();
    }
};

int main() {
    return 0;
}