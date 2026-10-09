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
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = slow;
        ListNode* mid = slow;

        // find mid
        while (fast){
            mid = slow;
            slow = slow->next;
            fast = fast->next ? fast->next->next : nullptr;
        }
        mid->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* nxt = nullptr;
        // reverse right side
        while (curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        ListNode* left = head;
        ListNode* leftNxt = nullptr;
        ListNode* right = prev;
        ListNode* rightNxt = nullptr;
        bool leftSide = true;
        // merge both
        while (right && left)
        {
            if (leftSide){
                leftNxt = left->next;
                left->next = right;
                left = leftNxt;
                leftSide = false;
            } else {
                rightNxt = right->next;
                right->next = left;
                right = rightNxt;
                leftSide = true;
            }
        }
        
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{0,1,2,3};

    ListNode* listNode3 = new ListNode(6, nullptr);
    ListNode* listNode2 = new ListNode(4, listNode3);
    ListNode* listNode1 = new ListNode(2, listNode2);
    ListNode* head = new ListNode(0, listNode1);


    Solution sol{};
    sol.reorderList(head);

    //output
    
}