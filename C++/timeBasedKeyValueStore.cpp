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

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()){
            // key not found
            return "";
        }
        const auto& vec = mp.at(key);
        int l = 0;
        int r = vec.size() -1;
        int res = -1;
        while (l<=r){
            int mid = ((r - l) / 2) + l;
            if (vec[mid].first <= timestamp){
                res = mid;
                l = mid+1;
            } else {
                r = mid -1;
            }
        }
        if (res < 0){
            return "";
        }
        return vec[res].second;
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> mp{};
};



// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{1,1,2};

    TimeMap timeMap{};
    timeMap.set("alice", "happy", 1);  // store the key "alice" and value "happy" along with timestamp = 1.
    std::cout << timeMap.get("alice", 1) << std::endl;           // return "happy"
    std::cout << timeMap.get("alice", 2) << std::endl;           // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
    timeMap.set("alice", "sad", 3);    // store the key "alice" and value "sad" along with timestamp = 3.
    std::cout << timeMap.get("alice", 3) << std::endl;           // return "sad"

    //output
    
}