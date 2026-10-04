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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* Next = nullptr;
        
        while (current != nullptr){
            Next = current->next;
            current->next = prev;
            prev = current;
            current = Next;
        }
        return prev;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{0,1,2,3};

    ListNode* listNode3 = new ListNode(3, nullptr);
    ListNode* listNode2 = new ListNode(2, listNode3);
    ListNode* listNode1 = new ListNode(1, listNode2);
    ListNode* head = new ListNode(0, listNode1);


    Solution sol{};
    sol.reverseList(head);

    //output
    
}