/**
 * In an N by N square grid, each cell is either empty (0) or blocked (1).
 * 
 * A clear path from top-left to bottom-right has length k if and only if it is composed 
 * of cells C_1, C_2, ..., C_k such that:
 * 
 * Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different 
 * and share an edge or corner)
 * 
 *  C_1 is at location (0, 0) (ie. has value grid[0][0])
 *  C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
 *  If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
 * 
 * Return the length of the shortest such clear path from top-left to bottom-right.  If 
 * such a path does not exist, return -1.
 * 
 * EXAMPLE:
 * Input: [[0,1],[1,0]]
 * Output: 2
 * 
 * EXAMPLE:
 * Input: [[0,0,0],[1,1,0],[1,1,0]]
 * Outpur: 4
 * 
 * EXAMPLE:
 * Input: [[1,0,0],[1,1,0],[1,1,0]]
 * Output: -1
 * 
 * EXAMPLE:
 * Input: [[0]]
 * Output: 1
 */

#include <iostream>
#include <queue>

class Solution {
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> d {{+0, -1},    // LEFT
                              {+0, +1},    // RIGHT
                              {-1, +0},    // UP
                              {+1, +0},    // DOWN
                              {+1, +1},    // RIGHT-DOWN
                              {+1, -1},    // LEFT-DOWN
                              {-1, +1},    // RIGHT-UP
                              {-1, -1}};   // LEFT-UP
public:
    int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
        int gsize {static_cast<int>(grid.size())};
        int dsize {static_cast<int>(d.size())};
        if(grid[0][0] == 1 || grid[gsize-1][gsize-1] == 1) return -1;
        if(gsize == 1 && grid[0][0] == 0) return 1;
        
        q.push({0,0});                          // mark starting point
        while(!q.empty()) {
            std::pair<int, int> p {q.front()};
            q.pop();
            int x  {p.first};
            int y  {p.second};
                
            for(int i {0}; i < dsize; ++i) {    // traverse in all directions
                int dx {x + d[i].first};
                int dy {y + d[i].second};
                
                // skip invalid points
                if(dx < 0 || dy < 0 || dx >= gsize || dy >= gsize) continue;
                if(grid[dx][dy] == 1 || grid[dx][dy] < 0) continue;
                
                grid[dx][dy] = grid[x][y] - 1;  // mark visited w/ distance
                q.push({dx, dy});               // push to queue
                
                if(dx == gsize-1 && dy == gsize-1) {
                    // arrived at destination
                    return (grid[dx][dy] * -1) + 1;
                }
            }
        }
        return -1;                              // no way found!
    }
};