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
        const std::string* shortStr{};
        const std::string* longStr{};
        // determine shortest string and fill map with it
        if (s1.size() < s2.size()){
            shortStr = &s1;
            longStr = &s2;
            windowSize = s1.size();
            fillMap(s1);
        } else {
            shortStr = &s2;
            longStr = &s1;
            windowSize = s2.size();
            fillMap(s2);
        }

        int l = 0;
        std::unordered_map<char, int> currentMap(chars);
        bool isResetNeeded = false;
        for (int r=0;r < longStr->size();r++){
            
            if (isResetNeeded){
                isResetNeeded = false;
                currentMap = chars;
            }
            currentMap[longStr->at(r)]--;

            // char not in map, or in map but count ran out
            while (r < longStr->size() && (currentMap.find(longStr->at(r)) == currentMap.end() || currentMap[longStr->at(r)] < 0)){
                isResetNeeded = true;
                r++;
                l = r;
            }
            if (windowSize == (r-l+1)){
                return true;
            }
        }
        return false;
    }
private:
    int windowSize = 0;
    std::unordered_map<char, int> chars{};

    void fillMap(const std::string& s){
        for (char c:s){
            chars[c]++;
        }
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

}