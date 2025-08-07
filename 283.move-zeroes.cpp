/*
 * @lc app=leetcode.cn id=283 lang=cpp
 * @lcpr version=30204
 *
 * [283] Move Zeroes
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
    void moveZeroes(vector<int>& nums) {
        int slow=0;
        int count=0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]==0){
                count++;
            }else{
                nums[slow]=nums[fast];
                slow++;
            }
        }
        int j=nums.size()-1;
        while(count--){
            nums[j]=0;
            j--;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,3,12]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

