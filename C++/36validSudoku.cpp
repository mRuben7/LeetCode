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
        if (board.empty() || board.size() < 9) return false;

        // check rows
        unordered_set<char> numsSeen{};
        for (const auto& row:board){
            if (row.empty() || row.size() < 9) return false;
            numsSeen.clear();
            for (char col:row){
                if (col=='.') continue;
                auto it = numsSeen.find(col);
                if(it != numsSeen.end())
                    return false;
                numsSeen.insert(col);
            }
        }
        numsSeen.clear();
        // check cols
        for (int cI = 0; cI<9;cI++){
            numsSeen.clear();
            for (int rI = 0; rI<9;rI++){
                if (board[rI][cI]=='.') continue;
                auto it = numsSeen.find(board[rI][cI]);
                if(it != numsSeen.end())
                    return false;
                numsSeen.insert(board[rI][cI]);
            }
        }
        
        numsSeen.clear();
        // check quadrants
        int rI = 0; //6 max
        int cI = 0; //6 max
        while (rI <= 6 && cI <= 6){
            numsSeen.clear();
            for (int r = 0; r<3;r++){
                for (int c = 0; c<3;c++){
                    if (board[rI+r][cI+c]=='.') continue;
                    auto it = numsSeen.find(board[rI+r][cI+c]);
                    if(it != numsSeen.end())
                        return false;
                    numsSeen.insert(board[rI+r][cI+c]);
                }
            }
            if (cI>=6){
                rI += 3;
                cI = 0;
            } else {
                cI += 3;
            }
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