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
        std::unordered_map<int, int> freqs{}; // num, appeareance freq
        for (int n:nums){
            freqs[n]++;
        }
        std::vector<pair<int, int>> vecFreqs{};
        for (auto freq:freqs){
            vecFreqs.emplace_back(freq.first, freq.second);
        }
        std::sort(vecFreqs.begin(), vecFreqs.end(),
                    [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
                        return a.second > b.second;
            });
        std::vector<int> res{};
        for(int i=0;i<k;i++){
            res.emplace_back(vecFreqs[i].first);
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