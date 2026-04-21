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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size()<2) return {nums[0]};
        std::unordered_map<int, int> freqs{};
        for (int n:nums){
            freqs[n]++;
        }
        std::map<int, int> orderedFreqs{};
        for (auto freq:freqs){
            orderedFreqs[freq.second] = freq.first;
        }
        vector<int> res{};
        auto it = orderedFreqs.end();
        it--;
        while (res.size() < k){
            res.emplace_back(it->second);
            if (it == orderedFreqs.begin()) break;
            it--;
        }
        return res;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{3,3,4};

    Solution sol{};

    //output
    auto vec = sol.topKFrequent(nums, 2);

    for (auto a : vec){
        std::cout << a << std::endl;
    }
}