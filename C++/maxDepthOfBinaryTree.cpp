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


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root){
            return depth--;
        }
        if (root == og){
            return max;
        }
        depth++;
        max = std::max(depth, max);
        maxDepth(root->left);
        maxDepth(root->right);
        return max;
    }
private:
    int depth = 1;
    int max = 0;
    TreeNode* og{};
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