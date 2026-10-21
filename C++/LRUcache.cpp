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
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val)
        : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int m_capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtEnd(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    void moveToEnd(Node* node) {
        remove(node);
        insertAtEnd(node);
    }

public:
    LRUCache(int capacity) : m_capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end())
            return -1;

        Node* node = it->second;
        moveToEnd(node);
        return node->val;
    }

    void put(int key, int value) {
        auto it = mp.find(key);

        if (it != mp.end()) {
            Node* node = it->second;
            node->val = value;
            moveToEnd(node);
            return;
        }

        Node* node = new Node(key, value);
        mp[key] = node;
        insertAtEnd(node);

        if (mp.size() > m_capacity) {
            Node* lru = head->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
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