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
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        int freq[26] = {};

        // Count the characters we need.
        for (char c : s1)
            freq[c - 'a']++;

        int remaining = s1.size();
        int l = 0;

        for (int r = 0; r < s2.size(); r++) {
            // Character enters the window.
            if (--freq[s2[r] - 'a'] >= 0)
                remaining--;

            // Keep the window the same size as s1.
            if (r - l + 1 > s1.size()) {
                if (++freq[s2[l] - 'a'] > 0)
                    remaining++;
                l++;
            }

            if (remaining == 0)
                return true;
        }

        return false;
    }
};



// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::string s1 = "abc";
    std::string s2 = "lecabee";

    std::cout << "has permutation --> " << (sol.checkInclusion(s1, s2)?"true":"false") << std::endl;
    std::cout << "-------------------------------------------\n"; // true
    s2 = "lecaabee";
    std::cout << "has permutation --> " << (sol.checkInclusion(s1, s2)?"true":"false") << std::endl;
    std::cout << "-------------------------------------------\n"; // false
    s1="adc";
    s2="dcda";
    std::cout << "has permutation --> " << (sol.checkInclusion(s1, s2)?"true":"false") << std::endl;
    std::cout << "-------------------------------------------\n"; // true

}