/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30204
 *
 * [18] 4Sum
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for(int k=0;k<nums.size();k++){
            //剪枝：三數和求的target為零，但此題target可能為負數
            //不能單純判斷nums[k]>target，因為負數累加後可能達到target值
            //如[-2, -1, 0, 0]，target=-3，-2>-3，但-2+(-1)+0+0=-3
            //nums[k]>=0代表當前值非負數，後面不可能出現負數湊出target值
            if(nums[k]>target && nums[k]>=0) break;
            //去重
            if(k>0 && nums[k]==nums[k-1]) continue;
            for(int i=k+1;i<nums.size();i++){
                //剪枝
                if(nums[k]+nums[i]>target && nums[k]+nums[i]>=0) break;
                //去重
                if(i>k+1 && nums[i]==nums[i-1]) continue;
                int left = i+1;
                int right = nums.size()-1;
                while(left<right){
                    //強制轉nums[k]為 long，使整個加總過程以 long 型別進行
                    //即使總和超過 int 最大值，也不會溢出
                    //如果全部以 int 加總後再轉為 long 也來不及，會先溢出
                    if((long)nums[k]+nums[i]+nums[left]+nums[right]>target){
                        right--;
                    }else if((long)nums[k]+nums[i]+nums[left]+nums[right]<target){
                        left++;
                    }else{
                        answer.push_back({nums[k], nums[i], nums[left], nums[right]});
                        while(left<right && nums[left]==nums[left+1])left++;
                        while(left<right && nums[right]==nums[right-1])right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */

