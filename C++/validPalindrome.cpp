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
    bool isPalindrome(string s) {
        if (s.empty())
            return true;

        for (int i=0, z=s.size()-1;i<s.size();i++,z--){
            if (!std::isalnum(s[i])){
                z++;
                continue;
            }
            if (!std::isalnum(s[z])){
                i--;
                continue;
            }
            if (std::tolower(s[i])!=std::tolower(s[z])){
                return false;
            }
        }
        return true;
    }

};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    
}