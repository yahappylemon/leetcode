/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num){
        for(int i=0;i<board.size();i++){
            if(board[i][col]==num){
                return false;
            }
        }
        for(int j=0;j<board.size();j++){
            if(board[row][j]==num){
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        // 判断9方格里是否重复
        for (int i = startRow; i < startRow + 3; i++) { 
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
    }
    // 返回bool，找到一個合法解就停止遞迴，提早結束
    bool backtracking(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isValid(board,i, j, k)){
                            board[i][j]=k;
                            bool result = backtracking(board);
                            if(result) return true;
                            board[i][j]='.';
                        }
                    }
                    // 空格嘗試1-9後都不符合結果
                    return false;
                }
            }
        }
        // 棋盤已經都填滿，沒有'.'
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
// @lc code=end

