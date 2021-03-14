#include <iostream>
#include <unordered_map>
#include <map>

class hash_pair {
    public:
    size_t operator() (const std::pair<int, int>& a) const {
        auto hash1 {std::hash<int>{}(a.first)};
        auto hash2 {std::hash<int>{}(a.second)};
        return hash1 ^ hash2;
    }
};

std::unordered_map<std::pair<int, int>, int, hash_pair> memo;
// std::map<std::pair<int, int>, int> memo;

int gridTraveller(int r, int c) {
    if(r == 0 || c == 0) return 0;
    if(r == 1 || c == 1) return 1;

    std::pair<int, int> p = std::pair<int, int>(r, c);
    auto it = memo.find(p);
    if(it != memo.end()) {
        return it->second;
    }

    memo.insert(std::pair<std::pair<int, int>, int>(p, gridTraveller(r - 1, c) + gridTraveller(r, c - 1)));

    return memo[p];
}


int main() {
    std::cout << gridTraveller(20,20);
    return 0;
}