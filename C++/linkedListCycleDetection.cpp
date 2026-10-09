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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head?head->next:nullptr;

        while (fast){
            if (slow == fast)
                return true;
            slow = slow->next;
            if (!fast)
                return false;
            if (!fast->next)
                return false;
            fast = fast->next->next;
        }
        return false;
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
    sol.hasCycle(head);

    //output
    
}