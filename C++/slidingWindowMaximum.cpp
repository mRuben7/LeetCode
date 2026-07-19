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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        return {};
    }
};




// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    vector<int> vec {1,2,1,0,4,2,6};
    int k = 3;

    for (auto a : sol.maxSlidingWindow(vec, k)){
        std::cout << "max is --> " << a << std::endl;
    }
    std::cout << "-------------------------------------------\n"; // 2,2,4,4,6
    

}