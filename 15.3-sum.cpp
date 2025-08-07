/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30204
 *
 * [15] 3Sum
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
#include <map>
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        //將數組由小到大排序
        //使用雙指針法的前提：數組要排序
        //數組可以排序的前提：答案不需要元素下標值
        sort(nums.begin(),nums.end());
        //i向後遍歷
        for(int i=0;i<nums.size();i++){
            //i如果大於0=>跳出循環，因為三數和不可能為0
            if(nums[i]>0) break;
            //檢查i和前一個數相同=>決定「是否該進入」本次迴圈
            //如果一樣，跳過這次，因為結果會和上一次相同
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                //i+left+right>0=>right向內縮，讓三數和變小
                if(nums[i]+nums[left]+nums[right]>0){
                    right--;
                //i+left+right<0=>left向外擴，讓三數和變大
                }else if(nums[i]+nums[left]+nums[right]<0){
                    left++;
                //i+left+right==0=>插入結果
                }else{
                    vector<int> sum = {nums[i],nums[left],nums[right]};
                    answer.push_back(sum);
                    //去除重複值，讓指標停在最後一個重複值的位置
                    //檢查left/right和下一個數相同=>決定「是否該跳過」接下來的解
                    //如果一樣，繼續向後移動，直到出現不同的值
                    while(left<right&&nums[right]==nums[right-1])right--;
                    while(left<right&&nums[left]==nums[left+1])left++;
                    //指標同時收縮，進入下一輪判斷
                    right--;
                    left++;
                }
            }
        }
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */

