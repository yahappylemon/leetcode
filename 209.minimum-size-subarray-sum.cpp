/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30204
 *
 * [209] Minimum Size Subarray Sum
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int length = INT_MAX;
        //滑動視窗起始位置
        int i=0;
        //滑動視窗終止位置
        for(int j=0; j<nums.size();j++){
            // 每次擴展一格
            sum+=nums[j];
            // 總和大於目標值，就縮小視窗
            // 檢視縮小後長度是否更短
            // 縮小直到不足目標值，跳出迴圈
            while(sum>=target){
                if(j-i+1<length) length=j-i+1;
                sum-=nums[i];
                i++;
            }
        }   
        return length==INT_MAX? 0:length;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

