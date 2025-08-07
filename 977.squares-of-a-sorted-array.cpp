/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30204
 *
 * [977] Squares of a Sorted Array
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
    // 负数平方之后可能成为最大数，因此数组平方後最大值在数组的两端
    // 不是最左边就是最右边，不可能是中间
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        //k指向result数组终止位置
        int k = nums.size()-1;
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            if(nums[i]*nums[i]>nums[j]*nums[j]){
                result[k]=nums[i]*nums[i];
                k--;
                i++;
            }else{
                result[k]=nums[j]*nums[j];
                k--;
                j--;
            }
        }
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */

