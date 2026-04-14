#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <optional>

using namespace std;

class Solution {
public:
    //function from leetcode goes here
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> seenNums;
        for(int i=0;i<nums.size();i++){
            int res = target - nums[i];
            auto it = seenNums.find(res);
            if(it != seenNums.end()){
                return {i, it->second};
            }
            seenNums.insert({nums[i], i});
        }
        return {};
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{1,1,2};

    Solution sol{};

    //output
    
}