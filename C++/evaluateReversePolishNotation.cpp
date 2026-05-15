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
        
        std::vector<int> stack{};
        for (const auto& t:tokens){
            if(t.empty())
                continue;
            char c = t[0];
            if(std::isdigit(c) || (c == '-' && t.size()>1)){
                stack.push_back(std::stoi(t)); // to transform from char to int properly
                continue;
            }
            int res;
            int preLast = *(stack.end() - 2);
            switch (c)
            {
            case '+':
                /* sum last two nums and pop them from the stack, then add the res to the stack */
                res = preLast + stack.back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back(res);
                break;
            case '-':
                res = preLast - stack.back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back(res);
                break;
            case '*':
                res = stack.back() * preLast;
                stack.pop_back();
                stack.pop_back();
                stack.push_back(res);
                break;
            case '/':
                res = preLast / stack.back();
                stack.pop_back();
                stack.pop_back();
                stack.push_back(res);
                break;
            
            default:
                break;
            }
        }

        return stack.back();
    }

};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<std::string> str{"1","2","+","3","*","4","-"};
    std::vector<std::string> str2{"2","1","+","3","*"};
    std::vector<std::string> str3{"4","13","5","/","+"};
    std::vector<std::string> str4{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    Solution sol{};

    //output
    std::cout << "str res = " << sol.evalRPN(str) << std::endl;
    std::cout << "-------------------------------------------\n";
    std::cout << "str 2 res = " << sol.evalRPN(str2) << std::endl;
    std::cout << "-------------------------------------------\n";
    std::cout << "str 3 res = " << sol.evalRPN(str3) << std::endl;
    std::cout << "-------------------------------------------\n";
    std::cout << "str 4 res = " << sol.evalRPN(str4) << std::endl;
    std::cout << "-------------------------------------------\n";

}