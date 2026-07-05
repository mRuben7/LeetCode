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
    bool checkInclusion(string s1, string s2) {

        return false;
    }
};



// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::string s1 = "abc";
    std::string s2 = "lecabee";

    std::cout << "has permutation --> " << (sol.checkInclusion(s1, s2)?"true":"false") << std::endl;
    std::cout << "-------------------------------------------\n"; // true

}