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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return l1;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{0,1,2,3};

    ListNode* listNode2 = new ListNode(3, nullptr);
    ListNode* listNode1 = new ListNode(2, listNode2);
    ListNode* head = new ListNode(1, listNode1);

    ListNode* listNode2_2 = new ListNode(6, nullptr);
    ListNode* listNode1_2 = new ListNode(5, listNode2_2);
    ListNode* head_2 = new ListNode(4, listNode1_2);


    Solution sol{};
    auto res = sol.addTwoNumbers(head, head_2);

    while (res){
        std::cout << res->val; // expected 579
        res = res->next;
    }

    //output
    
}