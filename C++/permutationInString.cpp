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
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        int winSize = s1.size();
        std::unordered_map<char, int> charAppeareancesMap{};
        std::unordered_map<char, int> originalMap{};
        for (char c:s1){
            charAppeareancesMap[c]++;
            originalMap[c]++;
        }
        int charsToConsume = charAppeareancesMap.size();

        int l = 0;
        for (int r=0;r < s2.size();r++){
            while ((r-l+1) > winSize){
                auto it = charAppeareancesMap.find(s2[l]);
                if (it != charAppeareancesMap.end()) {
                    it->second++;
                    if (charAppeareancesMap[s2[l]] == 0){
                        charsToConsume--;
                    }
                }
                l++;
            }
            auto it = charAppeareancesMap.find(s2[r]);

            // not found in map
            if (it == charAppeareancesMap.end()){
                l = r;
                charAppeareancesMap = originalMap;
                charsToConsume = charAppeareancesMap.size();
                continue;
            }

            charAppeareancesMap[s2[r]]--;

            if (charAppeareancesMap[s2[r]] < 0){
                charsToConsume++;
                continue;
            }

            if (charAppeareancesMap[s2[r]] == 0){
                charsToConsume--;
            }
            if (charsToConsume == 0){
                return true;
            }
        }
        return false;
    }
};



// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    Solution sol{};

    std::string s1 = "abc";
    std::string s2 = "lecabee";

    std::cout << "has permutation --> " << (sol.checkInclusion(s1, s2)?"true":"false") << std::endl;
    std::cout << "-------------------------------------------\n"; // true
    s2 = "lecaabee";
    std::cout << "has permutation --> " << (sol.checkInclusion(s1, s2)?"true":"false") << std::endl;
    std::cout << "-------------------------------------------\n"; // false
    s1="adc";
    s2="dcda";
    std::cout << "has permutation --> " << (sol.checkInclusion(s1, s2)?"true":"false") << std::endl;
    std::cout << "-------------------------------------------\n"; // true

}