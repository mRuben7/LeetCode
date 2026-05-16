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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.empty())
            return {};
        
        std::vector<int> res{};
        res.reserve(temperatures.size());
        int count = 0;

        for (int i=0; i<temperatures.size();i++){
            int resElem = 0;
            count = 1;
            for (int j=i+1; j<temperatures.size();j++){
                if (temperatures[j]>temperatures[i]){
                    resElem = count;
                    break;
                }
                count++;
            }
            res.push_back(resElem);
        }
        return res;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{30,38,30,36,35,40,28}; // expected [1,4,1,2,1,0,0]
    std::vector<int> nums2{22,21,20}; // expected 0,0,0
    std::vector<int> nums3{73,74,75,71,69,72,76,73}; // expected 1,1,4,2,1,1,0,0
    std::vector<int> nums4{30,40,50,60}; // expected 1,1,1,0
    std::vector<int> nums5{30,60,90}; // expected 1,1,0

    Solution sol{};

    //output
    std::cout << "arr for nums\n";
    for (const auto& num:sol.dailyTemperatures(nums)){
        std::cout << num << std::endl;
    }
    std::cout << "-------------------------------------------\n";
    std::cout << "arr for nums2\n";
    for (const auto& num:sol.dailyTemperatures(nums2)){
        std::cout << num << std::endl;
    }
    std::cout << "-------------------------------------------\n";
    std::cout << "arr for nums3\n";
    for (const auto& num:sol.dailyTemperatures(nums3)){
        std::cout << num << std::endl;
    }
    std::cout << "-------------------------------------------\n";
    std::cout << "arr for nums4\n";
    for (const auto& num:sol.dailyTemperatures(nums4)){
        std::cout << num << std::endl;
    }
    std::cout << "-------------------------------------------\n";
    std::cout << "arr for nums5\n";
    for (const auto& num:sol.dailyTemperatures(nums5)){
        std::cout << num << std::endl;
    }
    std::cout << "-------------------------------------------\n";
}