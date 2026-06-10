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
        char currentChar = s[0];
        int count = 0;
        maxSubstr maxSrt{};
        for (const char c:s){
            if (c == currentChar){
                count++;
            } else {
                if (count>maxSrt.length){
                    maxSrt.length = count;
                    maxSrt.character = currentChar;
                }
                currentChar = c;
                count = 1;
            }
        }
        if (count>maxSrt.length){
            maxSrt.length = count;
            maxSrt.character = currentChar;
        }

        int res = 0;
        int l = 0;
        std::unordered_multiset<char> diffs{};
        diffs.reserve(s.size());

        int r = 0;
        for (;r<s.size();r++){
            while (diffs.size()>k){
                res = std::max(res, r-1-l);
                diffs.erase(s[l]);
                l++;
            }
            if (s[r] != maxSrt.character){
                diffs.insert(s[r]);
            }
        }
        res = std::max(res, r-l-(s[r]!=maxSrt.character));
        return res;
    }
};



// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::string vals = "AAAB";

    std::cout << "first example " << sol.characterReplacement(vals, 0) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 5

}