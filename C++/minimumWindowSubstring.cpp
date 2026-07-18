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
    string minWindow(string s, string t) {
        std::string res{};
        if (s.size() < t.size()){
            return res;
        }

        std::unordered_map<char, int> charMap{};
        for (char c:t){
            charMap[c]++;
        }
        int count = charMap.size();

        int l = 0;
        for (int r=0;r < s.size();r++){
            if (charMap.find(s[r]) != charMap.end()){
                charMap[s[r]]--;
                if (charMap[s[r]] == 0){
                    count--;
                }
            }
            while (count == 0){
                if(res.empty() || res.size() > (r-l+1)){
                    res = s.substr(l, r-l+1);
                }
                if (charMap.find(s[l]) != charMap.end()){
                    charMap[s[l]]++;
                    if (charMap[s[l]] > 0){
                        count++;
                    }
                }
                l++;
            }
        }
        return res;
    }
};



// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::string s = "OUZODYXAZV";
    std::string t = "XYZ";

    std::cout << "min substr is --> " << (sol.minWindow(s, t)) << std::endl;
    std::cout << "-------------------------------------------\n"; // YXAZ
    

}