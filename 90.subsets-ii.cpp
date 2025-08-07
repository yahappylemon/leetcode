/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
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
    void backtracking(vector<int>& nums, int start, vector<bool> &used){
        result.push_back(temp);
        for(int i=start;i<nums.size();i++){
            // [1, 1, 2]
            // 樹層去重：前一次的1已經往後找過子集合，這次可以跳過
            // 前提是used[i-1]==false(前一個相同的元素沒有被使用過)
            // used[i-1]==true代表是正在往下遞迴的過程，而不是新的頭
            if(i>0 && nums[i]==nums[i-1] && used[i-1]==false) continue;
            temp.push_back(nums[i]);
            used[i]=true;
            backtracking(nums, i+1,used);
            temp.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 先排序，讓重複元素相鄰才可以去重
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backtracking(nums, 0, used);
        return result;
    }
};
// @lc code=end

