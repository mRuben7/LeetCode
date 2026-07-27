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
    int minEatingSpeed(vector<int>& piles, int h) {
        const int LBOUND = 1;
        int RBOUND = 1;
        for (int pile:piles){
            RBOUND = std::max(RBOUND, pile);
        }
        int m = RBOUND/2;
        int l = 1;
        int r = RBOUND;
        int res = r;

        while (l<r){
            int hNeeded = 0;
            m = l + (r - l) / 2;

            for (int pile:piles){
                hNeeded += ((pile + m-1)/m);
            }

            if (hNeeded > h){ // means its not valid, so increase speed
                l = m + 1;
            } else { // means its valid, so decrease speed
                res = std::min(res, m);
                r = m;
            }
        }
        return res;
    }
};





// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::vector<int> vec {25,10,23,4};

    std::cout << sol.minEatingSpeed(vec, 9) << std::endl;
    std::cout << "-------------------------------------------\n"; // 2
    

}