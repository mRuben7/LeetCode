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

        int64_t totalProd = 1;
        bool isThereAZero = false;

        for (int num:nums){
            if (num==0){
                isThereAZero = true;
                continue;
            }
            totalProd *= num;
        }
        
        std::cout << "total " << totalProd << std::endl;
        std::vector<int32_t> resVec(nums.size());

        for (int i=0;i<nums.size();i++){
            if (isThereAZero){
                resVec[i] = nums[i]==0 ? totalProd : 0;
            }else{
                resVec[i] = totalProd/nums[i];
            }
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