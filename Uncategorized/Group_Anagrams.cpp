/**
 * Given an array of strings strs, group the anagrams together. You can return the 
 * answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a different word 
 * or phrase, typically using all the original letters exactly once.
 * 
 * EXAMPLE:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 */

#include <iostream>
#include <unordered_map>// unordered_map
#include <vector>       // vector
#include <string>       // string
#include <algorithm>    // sort()

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> answer;
        std::unordered_map<std::string, int> uniqueGroups;
        std::pair<std::unordered_map<std::string, int>::iterator, bool> ret;
        int len {static_cast<int>(strs.size())};
        std::string sortedStr;

        for(int i {0}, grpId {0}; i < len; ++i) {
            // sort the string in alphabetical order
            sortedStr = strs[i];
            std::sort(sortedStr.begin(), sortedStr.end());
            
            // push the sorted string to the map (a collector of unique strings) along
            // with the unique grpId.
            // Idea is, if the map accepts the string - it also stores its unique grpId.
            // Else, it returns the grpId to which previous insertion belongs to.
            ret = uniqueGroups.emplace(sortedStr, grpId);
            
            if(ret.second == false) {   // group already exists
                // insert an entry to existing grpId 'ret.first->second'.
                answer[ret.first->second].push_back(strs[i]);
            } else {
                // As answer is vector<vector>, we need to insert an empty vector first to
                // be inserted at the poisition (linked list) and then make the entry in it.
                answer.push_back({});
                // insert new unique group with new(next) 'grpId'.
                answer[grpId].push_back(strs[i]);
                ++grpId;
            }
        }
        return answer;
    }
};

int main() {
    return 0;
}