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
#include <queue>

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
        if (!q.empty() and key == q.front()){
            q.pop();
        }
        q.push(key);
        return mp.at(key);
    }
    
    void put(int key, int value) {
        if (m_size >= m_capacity){
            mp.erase(q.front());
            q.pop();
            m_size--;
        } else {
            if (!q.empty() and key == q.front()){
                q.pop();
            }
        }
        q.push(key);

        mp[key] = value;
        m_size++;
    }

private:
    int m_capacity{};
    int m_size{};

    // key - value
    std::unordered_map<int, int> mp{};
    std::queue<int> q{};
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    LRUCache lRUCache(2);
    lRUCache.put(1, 10);  // cache: {1=10}
    std::cout << "get: " << lRUCache.get(1) << std::endl;      // return 10
    lRUCache.put(2, 20);  // cache: {1=10, 2=20}
    lRUCache.put(3, 30);  // cache: {2=20, 3=30}, key=1 was evicted
    std::cout << "get: " << lRUCache.get(2) << std::endl;      // returns 20 
    std::cout << "get: " << lRUCache.get(1) << std::endl;      // return -1 (not found)
    
}