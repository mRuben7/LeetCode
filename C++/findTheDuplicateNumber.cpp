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
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int s2 = 0;
        do {
            slow = nums[slow];
            s2 = nums[s2];
        } while (slow != s2);
        return s2;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{1,2,3,4,4};

    Solution sol{};

    //output
    std::cout << "sol: " << sol.findDuplicate(nums) << std::endl;
}