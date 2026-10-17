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


//Definition for singly-linked list.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;

        Node* prev = new Node(-1);
        Node* dummy = new Node(-1);

        int i = 0;
        /// holder index, random ptr and random index
        std::unordered_map<Node*, int> randomPtrAndIndex{};
        
        while (curr){
            Node* node = new Node(curr->val);
            prev->next = node;
            if (!dummy->next)
            dummy->next = node;
            prev = node;
            randomPtrAndIndex[curr->random];
            if (randomPtrAndIndex.find(curr) != randomPtrAndIndex.end()){
                randomPtrAndIndex[curr] = i;
            }
            curr = curr->next;
            i++;
        }
        
        std::unordered_map<int, Node*> newRandomIndexAndPtr{};
        
        for (auto& kv : randomPtrAndIndex){
            newRandomIndexAndPtr[kv.second];
        }
        
        std::unordered_map<int, int> holderAndRandomIndices{};
        i = 0;
        curr = head;
        while (curr){
            if (randomPtrAndIndex.find(curr->random) != randomPtrAndIndex.end()){
                holderAndRandomIndices[i] = randomPtrAndIndex[curr->random];
            }
            curr = curr->next;
        }

        i = 0;
        Node* newCurr = dummy->next;
        curr = head;
        while (newCurr){
            if (newRandomIndexAndPtr.find(i) != newRandomIndexAndPtr.end()){
                newRandomIndexAndPtr[i] = newCurr;
            }
            curr = curr->next;
            newCurr = newCurr->next;
            i++;
        }

        curr = head;
        i = 0;
        newCurr = dummy->next;

        while (newCurr){
            newCurr->random = newRandomIndexAndPtr[holderAndRandomIndices[i]];
            newCurr = newCurr->next;
            i++;
        }
        
        return dummy->next;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{0,1,2,3};

    Node* listNode3 = new Node(4, nullptr);
    Node* listNode2 = new Node(3, listNode3);
    Node* listNode1 = new Node(2, listNode2);
    Node* head = new Node(1, listNode1);

    // ListNode* head = new ListNode(1, nullptr);


    Solution sol{};
    auto res = sol.copyRandomList(head);

    int i = 0;
    while (res){
        std::cout << "i: " << i << ", val: " << res->val << std::endl;
        res = res->next;
        i++;
    }

    //output
    
}