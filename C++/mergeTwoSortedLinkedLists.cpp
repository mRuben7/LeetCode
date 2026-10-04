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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if (!list2){
            return list1;
        }

        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        
        while (list1 and list2){
            if (!head){
                if(list1->val <= list2->val){
                    head = list1;
                    prev = head;
                    list1 = list1->next;
                }else{
                    head = list2;
                    prev = head;
                    list2 = list2->next;
                }
                continue;
            }
            if(list1->val <= list2->val){
                prev->next = list1;
                prev = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                prev = list2;
                list2 = list2->next;
            }
        }
        if (!list1){
            prev->next = list2;
        }
        if (!list2){
            prev->next = list1;
        }
        return head;
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

    ListNode* listN3 = new ListNode(7, nullptr);
    ListNode* listN2 = new ListNode(5, listN3);
    ListNode* listN1 = new ListNode(3, listN2);
    ListNode* head2 = new ListNode(1, listN1);


    Solution sol{};
    sol.mergeTwoLists(head, head2);

    //output
    
}