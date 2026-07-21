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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;
        int m = (l + r) / 2;
        while (l<=r){
            if (matrix[m][0] <= target && matrix[m][matrix[m].size()-1] >= target){
                // inner bin search here
                return true;
            }
            if (target < matrix[m][0]){
                r = m - 1;
            } else {
                l = m + 1;
            }
            m = (l + r) / 2;
        }
        return false;
    }
};




// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::vector<vector<int>> vec {{1,2,4,8},{10,11,12,13},{14,20,30,40}};

    std::cout << sol.searchMatrix(vec, 34) << std::endl;
    std::cout << "-------------------------------------------\n"; // true
    

}