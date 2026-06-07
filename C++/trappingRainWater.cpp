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
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        int maxLeft = height[l];
        int maxRight = height[r];
        while (l < r){
            if (maxLeft < maxRight) {
                l++;
                if (maxLeft <= height[l]){
                    maxLeft = height[l];
                    continue;
                }
                res += maxLeft - height[l];
            } else {
                r--;
                if (maxRight <= height[r]){
                    maxRight = height[r];
                    continue;
                }
                res += maxRight - height[r];
            }
        }
        return res;
    }
};



// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::vector<int> heights{0,2,0,3,1,0,1,3,2,1};

    std::cout << "first example " << sol.trap(heights) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 9

}