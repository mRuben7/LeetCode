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
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return {};

        std::vector<int32_t> resVec(nums.size());

        int prefix = 1;
        for (int i=0;i<nums.size();i++){
            resVec[i] = prefix;
            prefix *= nums[i];
        }
        prefix = 1;
        for (int i=nums.size()-1;i>=0;i--){
            resVec[i] *= prefix;
            prefix *= nums[i];
        }

        return resVec;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> vecInt{1,2,4,6};
    std::vector<int> vecInt2{-1,0,1,2,3};

    Solution sol{};

    //output

    auto resVec = sol.productExceptSelf(vecInt);
    for(const auto& val:resVec){
        std::cout << val << std::endl;
    }

    std::cout << "-------------------------------------------\n";

    resVec = sol.productExceptSelf(vecInt2);
    for(const auto& val:resVec){
        std::cout << val << std::endl;
    }
    
}