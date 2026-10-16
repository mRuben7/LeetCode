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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* l = dummy;
        ListNode* r = head;
        for (int i = 0; i<n; i++){
            r = r->next;
        }
        while (r){
            l = l->next;
            r = r->next;
        }
        if (l->next){
            l->next = l->next->next;
        }
        return dummy->next;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{0,1,2,3};

    ListNode* listNode3 = new ListNode(4, nullptr);
    ListNode* listNode2 = new ListNode(3, listNode3);
    ListNode* listNode1 = new ListNode(2, listNode2);
    ListNode* head = new ListNode(1, listNode1);

    // ListNode* head = new ListNode(1, nullptr);


    Solution sol{};
    auto res = sol.removeNthFromEnd(head, 2);

    int i = 0;
    while (res){
        std::cout << "i: " << i << ", val: " << res->val << std::endl;
        res = res->next;
        i++;
    }

    //output
    
}