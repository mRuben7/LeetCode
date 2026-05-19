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
    //function from leetcode goes here
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (target<1 || position.empty() || position.size()<1)
            return 0;

        std::unordered_set<int> res;
        for (int i=0; i<position.size(); i++){
            int numOfMoves = target - position[i];
            int totalMoves = numOfMoves/speed[i];
            res.insert(totalMoves);
        }
        return res.size();
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    int target = 10;
    std::vector<int> positions{30,38,30,36,35,40,28};
    std::vector<int> speeds{30,38,30,36,35,40,28};

    Solution sol{};

    //output

}