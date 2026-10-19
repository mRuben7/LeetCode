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

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        prev = nullptr;
    }
    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
        prev = nullptr;
    }
    Node(int _val, Node* _prev, Node* _next) {
        val = _val;
        next = _next;
        prev = _prev;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {

        return 0;
    }
    
    void put(int key, int value) {
        Node* nod{};
        if (mp.find(key) != mp.end()){
            nod = mp.at(key);
            nod->prev->next = nod->next;
            nod->prev = tail;
            tail->next = nod;
            tail = nod;
            return;
        }


        nod = new Node(value);
        m_size++;

        if (m_size > m_capacity){
            // TODO delete on maps and move head to next one
            m_size--;
        }

        tail->next = nod;
        nod->prev = tail;
        tail = nod;

        mp[key] = nod;
    }

private:
    int m_capacity{};
    int m_size{};

    Node* head = new Node(-1);
    Node* tail = new Node(-1);

    // key - Node
    std::unordered_map<int, Node*> mp{};
    // TODO add Node to key map
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