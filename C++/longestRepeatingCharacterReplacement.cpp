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
        return 0;
    }
private:
    std::unordered_map<char, int> substrs{}; // cahr val, lenght
};



// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::string vals = "AAABABB";

    std::cout << "first example " << sol.characterReplacement(vals, 1) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 5

}