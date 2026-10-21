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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // get size
        int s = 0;
        auto curr = head;
        while (curr){
            s++;
            curr = curr->next;
        }
        int reversions = s / k;
        int mod = s % k;

        // revert
        ListNode* dummy = nullptr;
        curr = head;

        ListNode* prevTail = nullptr;
        ListNode* prev = nullptr;
        ListNode* tl = nullptr;

        for (int iRev = 0; iRev < reversions; iRev++){
            for (int i = 0; i < k; i++){
                auto nxt = curr->next;
                curr->next = prev;
                if (i==0)
                    tl = curr;
                prev = curr;
                curr = nxt;
            }
            if(prevTail)
                prevTail->next = prev;
            prevTail = tl;
            if (!dummy)
                dummy = prev;
        }
        tl->next = mod ? curr : nullptr;
        return dummy;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<ListNode*> vec{};
    const int size = 6;

    ListNode* dummy = new ListNode(-1);
    auto prev = dummy;

    for(int i = 1; i <= size; i++){
        auto nod = new ListNode(i);
        prev->next = nod;
        prev = nod;
    }

    Solution sol{};
    auto res = sol.reverseKGroup(dummy->next, 3);

    while(res){
        std::cout << res->val << ", ";
        res = res->next;
    }
    std::cout << std::endl;

    //output
    
}