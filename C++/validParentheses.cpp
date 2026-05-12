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
    bool isValid(string s) {
        if (s.empty()) return false;

        std::vector<char> openedPars{};
        openedPars.reserve(s.size()/2);

        for (char c:s){
            if (c=='[' || c=='{' || c=='('){
                openedPars.emplace_back(c);
                continue;
            }
            auto it = parMatch.find(c);
            if(it!=parMatch.end()){
                if (openedPars.empty()) return false;

                if(openedPars.back() != it->second){
                    return false;
                }
                openedPars.pop_back();
            }
        }
        return openedPars.empty();
    }

private:
    std::unordered_map<char, char> parMatch{
        {']', '['},
        {'}', '{'},
        {')', '('}
    };
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::string str{"[(])"};
    std::string str2{"([{}])"};

    Solution sol{};

    //output
    std::cout << "is valid = " << sol.isValid(str) << std::endl;
    std::cout << "-------------------------------------------\n";
    std::cout << "is valid = " << sol.isValid(str2) << std::endl;
    std::cout << "-------------------------------------------\n";

}