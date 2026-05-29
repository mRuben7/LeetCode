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

struct bar{
    int val;
    int width;
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;

        std::vector<bar> bars{};
        for (int i=0;i<heights.size();i++){
            bar b{heights[i], 0};
            int width = 0;
            int l = i-1;
            int r = i+1;
            bool canExpandLeft = true;
            bool canExpandRight = true;
            while (canExpandLeft || canExpandRight){
                if (l<0)
                    canExpandLeft = false;
                if (r>=heights.size())
                    canExpandRight = false;
                
                if (canExpandLeft){
                    if (heights[i]<= heights[l]){
                        width++;
                    } else {
                        canExpandLeft = false;
                    }
                }
                if (canExpandRight){
                    if (heights[i]<= heights[r]){
                        width++;
                    } else {
                        canExpandRight = false;
                    }
                }
                l--;
                r++;
            }
            b.width = ++width; // to add itself
            bars.push_back(b);
        }
        int max = 0;
        for (const auto& bar:bars){
            int area = bar.val * bar.width;
            if (area>max)
                max = area;
        }
        return max;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::vector<int> heights{2,1,5,6,2,3};

    std::cout << "first example " << sol.largestRectangleArea(heights) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 10

}