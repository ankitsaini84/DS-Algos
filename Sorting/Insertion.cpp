/**
 * NOTE:
 * Idea behind INSERTION sort is to pick an element from the array, and keep 
 * inserting it at its correct place in the resulting array. Pick next element &
 * keep repeating it until all the elements are inserted at their respective 
 * correct places.
 * 
 * IMP:
 * BEST sorting technique iff there are very few (around 15) elements to sort.
 * 
 * Time Complexity ~ O(n^2)
 * Space Complexity ~ O(n) - Implace sorting
 * 
 * NOTE: It's a STABLE SORT.
 */

#include <iostream>
#include <vector>

void sort(std::vector<int> &arr) {
    // Considering that all the elements on the left side of the wall are sorted.
    // Pick an element from right side of the wall, and checking its ideal position
    // from right to left in the sorted array, insert it when ideal position is found.

    // Now, Let's put the imaginary wall @ position 1 & assume 0th element to be 
    // sorted array.
    int len {static_cast<int>(arr.size())};
    int t {0};
    for(int w {1}; w < len; ++w) {
        // temporarily store the element @ the wall.
        t = arr[w];
        // start chekcing the ideal poistion for the element from (wall - 1) till start.
        for(int e {w-1}; e >= 0; --e) {
            // Unless we can find the element smaller than the element @ wall - 
            // keep pushing all the elements to right-side & put wall-element at eth pos.
            if(t < arr[e]) {
                arr[e+1] = arr[e];
                arr[e] = t;
            } else {    
            // if an element is found which is smaller than the element @ wall -
            // just put wall-element @ right-side of the element & break the loop.
                arr[e+1] = t;
                break;
            }
        }
    }
}

int main() {
        std::vector<int> arr {74, 32, 89, 55, 21, 64};

    sort(arr);

    for(auto element : arr) {
        std::cout << element << " ";
    }
    
    return 0;
}