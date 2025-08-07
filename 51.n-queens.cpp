/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
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
    // 二維數組
    vector<vector<string>> result;
    // 三維數組
    // vector<vector<vector<char>>> result;
    bool isValid(vector<string> &chessboard, int n, int row, int col){
        // // 同一列已經有皇后：不用檢查，因為每一列只會出現一個皇后
        // for(int i=0;i<n;i++){
        //     if(chessboard[row][i]=='Q'){
        //         return false;
        //     }
        // }
        //     y →
        // x   0   1   2   3   4
        // ↓ +---------------------
        // 0 | .   .   Q   .   .     
        // 1 | .   .   Q   .   .     
        // 2 | .   .   Q   .   .    
        // 3 | .   .   ?   .   .  
        // 同一行已經有皇后：只要檢查0到row，row到n還沒遞迴到，不用檢查
        for(int i=0;i<row;i++){
            if(chessboard[i][col]=='Q'){
                return false;
            }
        }
        //     y →
        // x   0   1   2   3   4
        // ↓ +---------------------
        // 0 | .   .   .   .   .     
        // 1 | Q   .   .   .   .     
        // 2 | .   Q   .   .   .    
        // 3 | .   .   ?   .   .    
        // 左上 ↖：座標變化 (i--, j--)（橫的和直的都往上、往左）
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
                //     y →
        // x   0   1   2   3   4
        // ↓ +---------------------
        // 0 | .   .   .   .   .     
        // 1 | .   .   .   .   Q     
        // 2 | .   .   .   Q   .    
        // 3 | .   .   ?   .   .   
        // 右上 ↗：座標變化 (i--, j++)（直的往上、橫的往右）
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;      
    }
    void backtracking(vector<string> &chessboard, int n, int row){
        if(row==n){
            result.push_back(chessboard);
            return;
        }
        // 棋盤寬度：同一列不同行擺放皇后
        for(int col=0;col<n;col++){
            if(isValid(chessboard, n, row ,col)){
                chessboard[row][col]='Q';
                // 棋盤高度：往下一列遞迴擺放皇后
                backtracking(chessboard, n, row+1);
                chessboard[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // 建立每列長度為 n、內容全為 '.' 的字串
        vector<string> chessboard(n, string(n, '.'));
        backtracking(chessboard, n, 0);
        // vector<vector<char>> chessboard(n, vector<char>(n,'.'));
        // 三維數組轉成二維數組
        // vector<vector<string>> answer(result.size());
        // for(int i=0;i<result.size();i++){
        //     for(int j=0;j<n;j++){
        //         string temp="";
        //         for(int k=0;k<n;k++){
        //             temp+=result[i][j][k];
        //         }
        //         answer[i].push_back(temp);
        //     }
        // }
        return result;
    }
};
// @lc code=end

