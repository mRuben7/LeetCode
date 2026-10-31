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
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        return validate(root, -1000000001, 1000000001);
    }
    bool validate(TreeNode* node, int l, int r){
        if (!node)
            return true;

        if(node->val <= l or node->val >= r)
            return false;

        return validate(node->left,l,node->val) and validate(node->right,node->val,r);
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n = nullptr;

    n2->left = n1;
    n2->right = n3;

    Solution sol{};
    std::cout << sol.isValidBST(n2) << std::endl; // expected true

    n2->left = nullptr;
    n2->right = nullptr;
    n1->left = n2;
    n1->right = n3;

    std::cout << sol.isValidBST(n1) << std::endl; // expected false

    //output
    
}