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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root->val == p->val){
            _p = root;
        }
        if (root->val == q->val){
            _q = root;
        }
        if (_q and _p){
            return root;
        }
        else{
            auto left = lowestCommonAncestor(root->left, p, q);
            auto right = lowestCommonAncestor(root->right, p, q);
            return left?left:right;
        }
        return nullptr;
    }

    TreeNode* _p{};
    TreeNode* _q{};
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    TreeNode* root = new TreeNode(1);
    TreeNode* c1 = new TreeNode(1);
    TreeNode* c2 = new TreeNode(2);
    TreeNode* c3 = new TreeNode(3);
    TreeNode* c4 = new TreeNode(4);
    TreeNode* c5 = new TreeNode(5);

    root->left = c1;

    Solution sol{};

    std::cout << "solution: " << (sol.isSubtree(root, c1)?"true":"false") << std::endl;

    //output
    
}