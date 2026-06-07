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
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2)
            return 0;
        int max = 0;
        int l = 0;
        int r = 1;

        for (;r<prices.size();r++){
            if (prices[r]<prices[l]){
                l=r;
                continue;
            }
            int gains = prices[r] - prices[l];
            max = std::max(max, gains);
        }
        return max;
    }
};



// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::vector<int> vals{10,1,5,6,7,1};

    std::cout << "first example " << sol.maxProfit(vals) << std::endl;
    std::cout << "-------------------------------------------\n"; // expected 6

}