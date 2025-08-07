/*
 * @lc app=leetcode.cn id=26 lang=cpp
 * @lcpr version=30204
 *
 * [26] Remove Duplicates from Sorted Array
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
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> set;
        int slow = 0;
        for(int fast=0; fast<nums.size();fast++){
            //該元素還沒出現過
            if(set.find(nums[fast])==set.end()){
                set.insert(nums[fast]);
                nums[slow]=nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */

