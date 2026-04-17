#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <optional>

using namespace std;

class Solution {
public:
    //function from leetcode goes here
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};
        if (strs.size() < 2) return {strs};

        vector<vector<string>> res{};

        for (auto str:strs){
            if (res.empty()){
                res.push_back({str});
                continue;
            }
            bool strIsAnagram = false;
            for (int i=0;i<res.size();i++){
                if(isAnagram(str, res[i][0])){
                    res[i].emplace_back(str);
                    strIsAnagram = true;
                    break;
                }
            }
            if(!strIsAnagram)
                res.push_back({str});
        }
        return res;
    }
private:
    bool isAnagram(const std::string& s1, const std::string& s2){
        if (s1.size() != s2.size()) return false;
        std::vector<uint16_t> cCount(26, 0);

        for (int i=0; i<s1.size();i++){
            cCount[s1[i]-'a']++;
            cCount[s2[i]-'a']--;
        }

        return std::all_of(cCount.begin(), cCount.end(), [](int x){return x==0;});;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{1,1,2};
    vector<string> strings ({"eat","tea","tan","ate","nat","bat"});

    Solution sol{};

    //output
    for (auto a : sol.groupAnagrams(strings)){
        std::cout << "---\n";
        for(auto b:a)
            std::cout << b << std::endl;
    }

}