/*
 * @lc app=leetcode.cn id=1 lang=cpp
 * @lcpr version=30204
 *
 * [1] Two Sum
 */


// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size();i++){
            int gap = target-nums[i];
            //不要用map[gap]判斷是否存在
            //因為下標0會被判為false並自動插入
            auto it = map.find(gap);
            if(it!=map.end()){
                return {map[gap], i};
            }else{
                map[nums[i]]=i;
            }
        }
        return {};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

