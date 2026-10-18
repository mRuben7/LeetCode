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

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()){
            return -1;
        }
        return mp.at(key);
    }
    
    void put(int key, int value) {
        if (m_capacity <= m_size){
            // TODO LRU logic
        }

        mp[key] = value;
    }

private:
    int m_capacity{};
    int m_size{};

    // key - value
    std::unordered_map<int, int> mp{};
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{1,2,3,4,4};

    LRUCache lRUCache(2);
    lRUCache.put(1, 10);  // cache: {1=10}
    std::cout << "get: " << lRUCache.get(1) << std::endl;      // return 10
    lRUCache.put(2, 20);  // cache: {1=10, 2=20}
    lRUCache.put(3, 30);  // cache: {2=20, 3=30}, key=1 was evicted
    std::cout << "get: " << lRUCache.get(2) << std::endl;      // returns 20 
    std::cout << "get: " << lRUCache.get(1) << std::endl;      // return -1 (not found)
    
}