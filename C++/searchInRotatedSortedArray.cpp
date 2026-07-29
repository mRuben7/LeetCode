#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <optional>
#include <cmath>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)  {
        int l = 0;
        int r = nums.size() - 1;
        while (l<r){
            int m = l + ((r - l) / 2);
            if(target == nums[m]){
                return m;
            }
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        int min = l;
        l = 0;
        r = nums.size() - 1;

        if (target <= nums[r]){
            l = min;
        } else {
            r = min - 1;
        }

        while (l <= r){
            int m = l + ((r - l) / 2);
            if(target == nums[m]){
                return m;
            }
            if (target < nums[m]){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }
};






// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::vector<int> vec {1};

    std::cout << sol.search(vec, 1) << std::endl;
    std::cout << "-------------------------------------------\n"; // 2
    

}