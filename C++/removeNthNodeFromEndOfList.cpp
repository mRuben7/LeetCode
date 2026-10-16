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
        ListNode* curr = head;
        int size = 0;
        while (curr){
            std::cout << "size: " << size << ", val: " << curr->val << std::endl;
            curr = curr->next;
            size++;
        }
        int nodeToDelete = size - n;
        std::cout << "size: " << size << std::endl;
        std::cout << "node to delete: " << nodeToDelete << std::endl;
        int i = 0;
        ListNode* prev = nullptr;
        curr = head;
        while (curr){
            if (i == nodeToDelete){
                if (!prev){
                    if (size < 2){
                        head = nullptr;
                    } else {
                        head = curr->next;
                    }
                } else {
                    prev->next = curr->next;
                }
                break;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        return head;
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