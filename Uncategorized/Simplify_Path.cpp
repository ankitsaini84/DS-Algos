/**
 * Given a string path, which is an absolute path (starting with a slash '/') to a file or directory
 * in a Unix-style file system, convert it to the simplified canonical path.
 * In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers
 * to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single 
 * slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.
 * 
 * The canonical path should have the following format:
 * 
 * The path starts with a single slash '/'.
 * Any two directories are separated by a single slash '/'.
 * The path does not end with a trailing '/'.
 * The path only contains the directories on the path from the root directory to the target 
 * file or directory (i.e., no period '.' or double period '..')
 * 
 * Return the simplified canonical path.
 * 
 * CONSTRAINTS:
 * 1 <= path.length <= 3000
 * path consists of English letters, digits, period '.', slash '/' or '_'.
 * path is a valid absolute Unix path.
 */

#include <iostream>
#include <sstream>          // stringstream
#include <deque>            // deque


/**
 * ALGO:
 * Since, it is easy to print deque both ways, we are going to use it here.
 * If element is '.' or '' (in case of //) -> skip it.
 * Else if element is '..' -> pop the last pushed element.
 * Else, just push the element/node to deque.
 * 
 * When done, push all the elements of deque to string.
 */
class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stringstream spath(path);  // convert string to stream
        std::deque<std::string> s {};
        std::string str {""};
        
        while(std::getline(spath, str, '/')) {
            if(str == "..") {
                if(!s.empty()) {
                    s.pop_back();
                }
            } else if(str == "." || str == "") {
                continue;
            } else {
                s.push_back(str);
            }
        }
        
        str = "";
        if(s.empty()) {
            return "/";
        } else {
            while(!s.empty()) {
                str.append("/");
                str.append(s.front());
                s.pop_front();
            }
        }
        
        return str;
    }
};

int main() {
    Solution s;
    std::cout << "Canonical Path : " << s.simplifyPath("/a//b////c/d//././/..") << "\n";
    return 0;
}