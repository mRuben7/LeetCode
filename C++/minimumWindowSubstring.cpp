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
        
        return {};
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