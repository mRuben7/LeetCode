#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <optional>

using namespace std;

class Solution {
public:
    //function from leetcode goes here
    bool isAnagram(string s, string t) {
        // return std::is_permutation(s.begin(), s.end(), t.begin());
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); ++i) {
            size_t pos = t.find(s[i]);
            if(pos == std::string::npos){
                return false;
            } 
            t.erase(pos, 1);
        }
        if (!t.empty()) return false;
        return true;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{1,1,2};

    Solution sol{};

    //output
    std::cout << sol.isAnagram("anagram", "nagaram") << std::endl;

}