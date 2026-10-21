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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;

        while (true){
            int min = 21000;
            int ind = 0;
            for (int i = 0; i < lists.size(); i++){
                auto nod = lists[i];
                if(!nod){
                    continue;
                }
                if (nod->val < min){
                    min = nod->val;
                    ind = i;
                }
            }
            if (min == 21000)
                break;

            auto& nod = lists[ind];

            prev->next = nod;
            prev = nod;

            nod = nod ? nod->next : nullptr;
        }
        return dummy->next;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<ListNode*> vec{};

    ListNode* listNode2 = new ListNode(4, nullptr);
    ListNode* listNode1 = new ListNode(2, listNode2);
    ListNode* head = new ListNode(1, listNode1);

    vec.emplace_back(head);

    listNode2 = new ListNode(5, nullptr);
    listNode1 = new ListNode(3, listNode2);
    head = new ListNode(1, listNode1);

    vec.emplace_back(head);

    listNode1 = new ListNode(6, nullptr);
    head = new ListNode(3, listNode1);

    vec.emplace_back(head);


    Solution sol{};
    sol.mergeKLists(vec);

    //output
    
}