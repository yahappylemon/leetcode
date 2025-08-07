/*
 * @lc app=leetcode.cn id=3487 lang=cpp
 * @lcpr version=30204
 *
 * [3487] Maximum Unique Subarray Sum After Deletion
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
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> mymap;
        vector<int> newarr;
        int backup=INT_MIN;
        int sum=0;
        for(int i:nums){
            //去除負數
            if(i>0) newarr.push_back(i);
            //避免為空
            else backup=max(backup, i);
        }
        //去除重複
        for(int i:newarr){
            if(!mymap[i]){
                mymap[i]++;
            }
        }
        for(pair<int,int> i:mymap){
            sum+=i.first;
        }
        return newarr.size()==0?backup:sum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,-1,-2,1,0,-1]\n
// @lcpr case=end

 */

