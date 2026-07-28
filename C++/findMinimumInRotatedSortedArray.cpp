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
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l<r){
            int m = l + ((r - l) / 2);
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};






// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::vector<int> vec {3,4,5,6,1,2};

    std::cout << sol.findMin(vec) << std::endl;
    std::cout << "-------------------------------------------\n"; // 2
    

}