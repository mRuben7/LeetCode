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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (res)
            return res;
        if (!root and !subRoot)
            return true;
        if (!root or !subRoot)
            return false;

        if (root->val == subRoot->val){
            res = isSameTree(root, subRoot);
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left or right;
    }
    bool isSameTree (TreeNode* n1, TreeNode* n2){
        if (!n1 and !n2)
            return true;
        if (!n1 or !n2)
            return false;
        if (n1->val != n2->val)
            return false;

        return isSameTree(n1->left, n2->left) and isSameTree(n1->right, n2->right);
    }
    bool res = false;
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