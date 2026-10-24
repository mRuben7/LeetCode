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
    int diameterOfBinaryTree(TreeNode* root) {
        auto a = DFS(root);

        return max;
    }

private:
    int DFS(TreeNode* node){
        if (!node)
            return 0;
        auto left = DFS(node->left);
        auto right = DFS(node->right);
        max = std::max(max, (left + right));
        return 1 + std::max(left, right);
    }
    int max = 0;
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

    root->right = c2;
    c2->left = c3;
    c2->right = c4;
    c3->left = c5;

    Solution sol{};

    std::cout << "solution: " << sol.diameterOfBinaryTree(root) << std::endl;

    //output
    
}