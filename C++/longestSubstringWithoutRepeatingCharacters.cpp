#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <optional>
#include <cmath>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        int max = 0;
        int l = 0;
        for (int r=0;r<s.size();r++){
            while(seenChars.count(s[r])){
                seenChars.erase(s[l]);
                l++;
            }
            max = std::max(max, (r-l)+1);
            seenChars.insert(s[r]);
        }
        return max;
    }
private:
    std::unordered_set<char> seenChars{};
};



// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::string vals = "zxyzxyz";

    std::cout << "first example " << sol.lengthOfLongestSubstring(vals) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 3

}