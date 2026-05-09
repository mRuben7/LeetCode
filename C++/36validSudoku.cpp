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

class Solution {
public:
    //function from leetcode goes here
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty()) return false;

        for (const auto& row:board){
            if (row.empty()) return false;
        }

        return true;
    }
};


// === Debug part ==============================================
// use clang++ -std=c++20 template.cpp -o template to compile

int main(){
    //example input
    std::vector<int> nums{1,1,2};
    vector<vector<char>> board{
                                {'1','2','.','.','3','.','.','.','.'},
                                {'4','.','.','5','.','.','.','.','.'},
                                {'.','9','8','.','.','.','.','.','3'},
                                {'5','.','.','.','6','.','.','.','4'},
                                {'.','.','.','8','.','3','.','.','5'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','.','.','.','.','.','2','.','.'},
                                {'.','.','.','4','1','9','.','.','8'},
                                {'.','.','.','.','8','.','.','7','9'}
                            };
    vector<vector<char>> board2{
                                {'1','2','.','.','3','.','.','.','.'},
                                {'4','.','.','5','.','.','.','.','.'},
                                {'.','9','1','.','.','.','.','.','3'},
                                {'5','.','.','.','6','.','.','.','4'},
                                {'.','.','.','8','.','3','.','.','5'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','.','.','.','.','.','2','.','.'},
                                {'.','.','.','4','1','9','.','.','8'},
                                {'.','.','.','.','8','.','.','7','9'}
                            };

    Solution sol{};

    //output
    
    std::cout << "first board is " << (sol.isValidSudoku(board)?"valid":"invalid") << std::endl;

    std::cout << "-------------------------------------------\n";

    std::cout << "second board is " << (sol.isValidSudoku(board2)?"valid":"invalid") << std::endl;
}