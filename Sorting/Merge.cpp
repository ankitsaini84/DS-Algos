#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, const int s, const int m, const int e) {
    std::vector<int> arr1 {};
    std::vector<int> arr2 {};

    for(int i {s}; i < m; ++i) {
        arr1.push_back(arr[i]);
    }
    for(int i {m}; i < e; ++i) {
        arr2.push_back(arr[i]);
    }

    int a1 {0};
    int a2 {0};
    int e1 {static_cast<int>(arr1.size())};
    int e2 {static_cast<int>(arr2.size())};
    for(int i {s}; i < e; ++i) {
        if(a1 == e1) {
            arr[i] = arr2[a2];
            ++a2;
        }
        else if(a2 == e2) {
            arr[i] = arr1[a1];
            ++a1;
        }
        else if(arr1[a1] < arr2[a2]) {
            arr[i] = arr1[a1];
            ++a1;
        } else {
            arr[i] = arr2[a2];
            ++a2;
        }
    }
}

void msort(std::vector<int> &arr, const int start, const int end) {
    
    if(end - start <= 1) {
        return;
    }

    const int median = start + ((end - start) / 2);

    msort(arr, start, median);
    msort(arr, median, end);

    merge(arr, start, median, end);
}

void sort(std::vector<int> &arr) {
    int len {static_cast<int>(arr.size())};
    msort(arr, 0, len);
}

int main() {
    std::vector<int> arr {74, 32, 89, 55, 21, 64};
    
    sort(arr);

    for(auto element : arr) {
        std::cout << element << " ";
    }
    
    return 0;
}