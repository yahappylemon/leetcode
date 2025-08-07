/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
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
    void backtracking(vector<int>& nums, vector<bool>& used){
        // 終止條件：和原本的陣列大小相同
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return;
        }
        // 排列：順序不同視為不同(排列是有序的)
        // 每次從頭遍歷：i=0，順序不同要重複取
        // 利用used陣列確定該元素是否選過
        // 如：[1,2]取過，[2,1]還是要取
        for(int i=0;i<nums.size();i++){
            if(used[i]==true) continue;
            temp.push_back(nums[i]);
            used[i]=true;
            backtracking(nums, used);
            used[i]=false;
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end

