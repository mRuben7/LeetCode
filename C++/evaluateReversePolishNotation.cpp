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
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
            return 0;
        
        int res = 0;
        std::vector<int> stack{};
        for (const auto& t:tokens){
            if(t.empty())
                continue;
            char c = t[0];
            if(std::isdigit(c)){
                stack.push_back(c);
                continue;
            }
            switch (c)
            {
            case '+':
                /* sum last two nums and pop them from the stack */
                break;
            
            default:
                break;
            }
        }
    }

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