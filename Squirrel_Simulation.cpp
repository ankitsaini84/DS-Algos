/**
 * There's a tree, a squirrel, and several nuts. Positions are represented by the cells
 * in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect 
 * all the nuts and put them under the tree one by one. The squirrel can only take at 
 * most one nut at one time and can move in four directions - up, down, left and right, 
 * to the adjacent cell. The distance is represented by the number of moves. 
 * 
 * EXAMPLE:
 * Input: 
 * Height : 5
 * Width : 7
 * Tree position : [2,2]
 * Squirrel : [4,4]
 * Nuts : [[3,0], [2,5]]
 * Output: 12
 * 
 * NOTES:
 * All given positions won't overlap.\
 * The squirrel can take at most one nut at one time.
 * The given positions of nuts have no order.
 * Height and width are positive integers. 3 <= height * width <= 10,000.
 * The given positions contain at least one nut, only one tree and one squirrel.
 */

#include <iostream>
#include <vector>

class Solution {
    int distance(std::vector<int> p1, std::vector<int> p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    
    int maximum(const int a, const int b) {
        return a > b ? a : b;
    }
public:
    int minDistance(
        int height, 
        int width, 
        std::vector<int>& tree, 
        std::vector<int>& squirrel, 
        std::vector<std::vector<int>>& nuts) {
        
        int totalDistance {0};
        int maxCost {-100001};
        for(auto nut : nuts) {
            // adding all the distances of the 
            // nuts - to & fro from the tree.
            totalDistance += 2 * distance(tree, nut);

            // But, 1 but will be picked by the squirrel
            // on her way to the tree. We'll need to deduct
            // the 'from' distance of that nut from the tree
            // add the distance of that nut from the squirel.
            // Selection of that nut depends upon the following
            // factors - 
            // It should be nearest to the squirrel but farthest
            // from the tree.
            // Thus,
            maxCost = maximum(maxCost, distance(tree, nut) - distance(squirrel, nut));
        }
        totalDistance -= maxCost;
        return totalDistance;
    }
};

int main() {
    Solution s;
    std::vector<int> tree {0,1};
    std::vector<int> squirrel {0,0};
    std::vector<std::vector<int>> nuts {{0,2}};
    std::cout << "Minimum Distance is " << s.minDistance(1, 3, tree, squirrel, nuts);
    return 0;
}