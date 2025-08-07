/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
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
    vector<vector<int>> result;
    vector<int> temp;
    void backtracking(int n, int k, int start){
        // 終止條件：找到k個元素
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
        // 組合：順序不同視為相同
        // 每次往後取：i=start，避免重複取相同組合
        // 如：[1,2]取過，[2,1]就不會出現
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            // 下一層從 i+1 開始，避免重複
            backtracking(n, k, i+1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};
// @lc code=end

