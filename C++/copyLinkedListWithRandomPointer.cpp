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

        std::unordered_map<Node*, Node*> oldNodeToNewNodePtrs;
        
        while (curr){
            Node* node = new Node(curr->val);
            
            if (!dummy->next)
                dummy->next = node;

            prev->next = node;
            prev = node;

            oldNodeToNewNodePtrs[curr] = node;
            
            curr = curr->next;
        }

        curr = head;
        prev = new Node(-1);
        Node* node = dummy->next;

        while (curr){
            if (!curr->random){
                curr = curr->next;
                node = node->next;
                continue;
            }

            // auto rndm = oldNodeToNewNodePtrs[curr->random];
            node->random = oldNodeToNewNodePtrs[curr->random];

            curr = curr->next;
            node = node->next;
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

    head->random = nullptr;
    listNode1->random = listNode2;
    listNode2->random = listNode2;
    listNode3->random = listNode1;

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