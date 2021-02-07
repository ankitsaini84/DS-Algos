#include <iostream>
#include <vector>

/**
 * NOTE:
 * Idea behind SELETION sort is to find the minimum element & bring it
 * to the begginning of the array. Then, find next smallest & keep
 * repeating it until all the elements are sorted.
 * 
 * IMP:
 * BEST sorting technique iff SWAPS are VERY COSTLY,
 * as, we can only make 'n' swaps at max - 1 for 
 * each unsorted element in array/list.
 * 
 * Time Complexity ~ O(n^2)
 * Space Complexity ~ O(n) - Implace sorting
 * 
 * NOTE: It's a STABLE SORT.
 */

void sort(std::vector<int> &arr) {
    int len {static_cast<int>(arr.size())};
    int min {0};
    int tmp {0};
    for(int i {0}; i < len; ++i) {
        // find minimum in arr starting from 'i'
        min = i;
        for(int j {i}; j < len; ++j) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        // if 'i' is still not minimum - swap
        if(min != i) {
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}

int main() {
    std::vector<int> arr {74, 32, 89, 55, 21, 64};

    sort(arr);

    for(auto element : arr) {
        std::cout << element << " ";
    }
}