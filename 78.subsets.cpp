/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
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
    // 展開迴圈：for 迴圈（組合）
    // 每個位置開始向後遍歷
    void backtracking(vector<int>& nums, int start){
        // 子集合：每條路徑經過都要收集
        // 排列、組合：收集葉子節點
        result.push_back(temp);
        for(int i=start; i<nums.size();i++){
            temp.push_back(nums[i]);
            backtracking(nums, i+1);
            temp.pop_back();
        }
    }
    // 決策樹：選 / 不選（分支）
    // 每個元素做「要 / 不要」二選一
    void dfs(vector<int>& nums, int start) {
        if (start == nums.size()) {
            result.push_back(temp);
            return;
        }

        // 不選 nums[i]
        dfs(nums, start + 1);

        // 選 nums[i]
        temp.push_back(nums[start]);
        dfs(nums, start + 1);
        temp.pop_back(); // 回溯
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // backtracking(nums, 0);
        dfs(nums,0);
        return result;
    }
};
// @lc code=end

