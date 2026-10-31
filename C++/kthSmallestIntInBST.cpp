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
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return vals[k-1];
    }
    std::vector<int> vals{};
    int dfs(TreeNode* node){
        if (!node)
            return -1;

        int l = dfs(node->left);
        vals.push_back(node->val);
        int r = dfs(node->right);
        return node->val;

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


    n5->left = n3;
    n5->right = n6;
    n3->left = n2;
    n3->right = n4;
    n2->left = n1;



    Solution sol{};
    std::cout << sol.kthSmallest(n5, 5) << std::endl; // expected 5

    //output
    
}