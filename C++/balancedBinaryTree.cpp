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
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return m_isBalanded;
    }
private:
    int dfs(TreeNode* node){
        if (!node)
            return 0;
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        auto diff = std::abs(left - right);
        if (diff >= 2)
            m_isBalanded = false;
        return 1 + left + right;
    }
    bool m_isBalanded = true;
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
    c3->left = c4;
    c4->left = c5;

    Solution sol{};

    std::cout << "solution: " << (sol.isBalanced(root)?"true":"false") << std::endl;

    //output
    
}