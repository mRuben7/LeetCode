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

struct maxSubstr
{
    int length{0};
    char character;
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> freq;

        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            maxFreq = std::max(maxFreq, freq[s[right]]);

            while ((right - left + 1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }

            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};



// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::string vals = "XYYX";

    std::cout << "first example " << sol.characterReplacement(vals, 2) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 4

}