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
struct Node {
    int val;
    Node *next;

    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;

        Node* prev = new Node();
        Node* dummy = new Node(-1);

        while (curr){
            Node* node = new Node(curr->val);
            prev->next = node;
            if (!dummy->next)
                dummy->next = node;
            prev = node;
            curr = curr->next;
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