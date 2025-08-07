/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
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
    void backtracking(vector<int> &candidates, int target, int sum, vector<bool> &used, int start){
        if(sum>target) return;
        if(sum==target) result.push_back(temp);
        for(int i=start;i<candidates.size();i++){
            // [1, 1, 2, 5, 6, 7, 10]
            // 樹層去重：前一次的1已經往後找過組合加總，這次可以跳過
            // 前提是used[i-1]==false(前一個相同的元素沒有被使用過)
            // used[i-1]==true代表是正在往下遞迴的過程，而不是新的頭
            if(i>0 && candidates[i]==candidates[i-1] && used[i-1]==false) continue;
            temp.push_back(candidates[i]);
            used[i]=true;
            sum+=candidates[i];
            backtracking(candidates, target, sum, used, i+1);
            temp.pop_back();
            used[i]=false;
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        // 先排序，讓重複元素相鄰才可以去重
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used, 0);
        return result;
    }
};
// @lc code=end

