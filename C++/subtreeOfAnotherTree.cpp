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

        if (!subOG){
            subOG = subRoot;
        }

        if (subRoot == subOG){
            if (root->val == subRoot->val){
                bool left = isSubtree(root->left, subRoot->left);
                bool right = isSubtree(root->right, subRoot->right);
                res = left and right;
            } else {
                isSubtree(root->left, subRoot);
                isSubtree(root->right, subRoot);
            }
        } else {
            if (root->val == subRoot->val){
                bool left = isSubtree(root->left, subRoot->left);
                bool right = isSubtree(root->right, subRoot->right);
                return left and right;
            } else {
                return false;
            }
        }
        return res;
        // Base cases:
        // If res = true --> return true
        // If both null —>  return true
        // If !root or !sub —> return false;
        // If both vals eq —> return true;

        // Iterate root until node is equal to sub root
	    //     then check both
    }
    TreeNode* subOG = nullptr;
    bool res = false;
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    TreeNode* root = new TreeNode(1);
    TreeNode* c2 = new TreeNode(2);
    TreeNode* c3 = new TreeNode(3);
    TreeNode* c4 = new TreeNode(4);
    TreeNode* c5 = new TreeNode(5);

    root->left = c2;
    root->right = c3;
    c2->left = c4;
    c2->right = c5;

    Solution sol{};

    std::cout << "solution: " << (sol.isSubtree(root, c2)?"true":"false") << std::endl;

    //output
    
}