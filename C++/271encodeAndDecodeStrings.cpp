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
    //function from leetcode goes here
    string encode(vector<string>& strs) {
        if (strs.empty()) return {};

        std::string res{};
        for (const auto& str:strs){
            std::string tmpStr{};
            for (char c:str){
                tmpStr.push_back(c-CODING_MOVEMENT);
            }
            res.append(tmpStr);
            res.push_back(ETX);
            tmpStr.clear();
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};

        std::vector<std::string> res{};
        std::string tempStr{};

        for (char c:s){
            if (c==ETX){
                res.emplace_back(tempStr);
                tempStr.clear();
                continue;
            }
            tempStr.push_back(c+CODING_MOVEMENT);
        }
        return res;
    }

private:
    const char ETX = 3;
    const char CODING_MOVEMENT = 10;
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{1,1,2};

    Solution sol{};

    //output
    
}