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
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size()-1;
        int maxArea = 0;

        while (i<j){
            // int height = heights[i]<=heights[j]?heights[i]:heights[j];
            int height = 0;
            int width = j-i;
            if(heights[i]<=heights[j]){
                height = heights[i];
                i++;
            } else {
                height = heights[j];
                j--;
            }
            int area = height*width;
            maxArea = area>maxArea?area:maxArea;
        }

        return maxArea;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::vector<int> heights{1,7,2,5,4,7,3,6};

    std::cout << "first example " << sol.maxArea(heights) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 36

}