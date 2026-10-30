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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        std::vector<std::vector<int>> res;
        std::vector<TreeNode*> s1{};
        std::vector<TreeNode*> s2{};
        s1.push_back(root);

        while(!s1.empty() or !s2.empty()){
            std::vector<int> tmp{};
            if (s1.empty()){
                for (auto n : s2){
                    if(!n)
                        continue;
                    tmp.push_back(n->val);
                    s1.push_back(n->left);
                    s1.push_back(n->right);
                }
                s2.clear();
            } else {
                for (auto n : s1){
                    if(!n)
                        continue;
                    tmp.push_back(n->val);
                    s2.push_back(n->left);
                    s2.push_back(n->right);
                }
                s1.clear();
            }
            if (!tmp.empty())
                res.push_back(tmp);
        }
        return res;
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


    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;


    Solution sol{};
    auto a = sol.levelOrder(n1);

    int i = 0;
    for (auto lvl : a){
        std::cout << "--- level " << i++ << " ---" << std::endl;
        for (auto nodes : lvl){
            std::cout << nodes << ", ";
        }
        std::cout << std::endl;
    }

    //output
    
}