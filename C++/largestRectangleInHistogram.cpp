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
    int leftExtendableIndex;
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;

        int maxArea = 0;
        std::vector<bar> stack{};
        stack.reserve(heights.size());

        for (int i=0;i<heights.size();i++){
            bar b{};
            b.val = heights[i];

            if (i==0){
                b.leftExtendableIndex = i;
                stack.push_back(b);
                continue;
            }
            if (heights[i]>=stack.back().val){
                b.leftExtendableIndex = i;
                stack.push_back(b);
                continue;
            }

            int lastIndex = i;
            while (heights[i]<stack.back().val){
                // compute area 
                int width = i - stack.back().leftExtendableIndex;
                lastIndex = stack.back().leftExtendableIndex;
                int area = stack.back().val * width;
                maxArea = area>maxArea?area:maxArea;
                // pop
                stack.pop_back();
            } 
            b.leftExtendableIndex = lastIndex;
            stack.push_back(b);
        }

        // compute what's left on the stack

        return maxArea;
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