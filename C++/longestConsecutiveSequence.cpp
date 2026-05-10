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
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return {};
        std::sort(nums.begin(), nums.end());
        int maxCount=0;
        int count=1;
        int prevElem=0;
        bool isFirstElem = true;
        for (int n:nums){
            if (isFirstElem){
                isFirstElem = false;
                prevElem = n;
                continue;
            }
            if (prevElem == n){
                prevElem = n;
                continue;
            }
            if (n==(prevElem+1)){
                count++;
            } else {
                if (count > maxCount)
                    maxCount = count;
                count = 1;
            }
            prevElem = n;
        }
        return maxCount?maxCount:count;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{2,20,4,10,3,4,5}; // expected 4
    std::vector<int> nums2{100,4,200,1,3,2}; // expected 4
    std::vector<int> nums3{0,3,7,2,5,8,4,6,0,1}; // expected 9
    std::vector<int> nums4{1,0,1,2}; // expected 3
    std::vector<int> nums5{0,3,2,5,4,6,1,1}; // expected 7

    Solution sol{};

    //output
    std::cout << "combos for nums = " << sol.longestConsecutive(nums) << std::endl;
    std::cout << "-------------------------------------------\n";
    std::cout << "combos for nums2 = " << sol.longestConsecutive(nums2) << std::endl;
    std::cout << "-------------------------------------------\n";
    std::cout << "combos for nums3 = " << sol.longestConsecutive(nums3) << std::endl;
    std::cout << "-------------------------------------------\n";
    std::cout << "combos for nums4 = " << sol.longestConsecutive(nums4) << std::endl;
    std::cout << "-------------------------------------------\n";
    std::cout << "combos for nums5 = " << sol.longestConsecutive(nums5) << std::endl;
    std::cout << "-------------------------------------------\n";
}