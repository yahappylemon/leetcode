/*
 * @lc app=leetcode.cn id=454 lang=cpp
 * @lcpr version=30204
 *
 * [454] 4Sum II
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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        int count=0;
        for(int i:nums1){
            for(int j:nums2){
                map[i+j]++;
            }
        }
        for(int i:nums3){
            for(int j:nums4){
                int target = 0-(i+j);
                //找到互補的數字
                if(map.find(target)!=map.end()){
                    count+=map[target];
                }
            }
        }
        return count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n[-2,-1]\n[-1,2]\n[0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n[0]\n[0]\n
// @lcpr case=end

 */

