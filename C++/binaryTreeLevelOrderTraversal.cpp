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
        std::deque<TreeNode*> q{};
        q.push_back(root);

        while (!q.empty()){
            int size = q.size();
            std::vector<int> tmp{};
            for (int i = 0; i<size; i++){
                auto n = q.front();
                q.pop_front();
                if (!n)
                    continue;
                tmp.push_back(n->val);
                q.push_back(n->left);
                q.push_back(n->right);
            }
            if(!tmp.empty())
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