/*
 * @lc app=leetcode.cn id=303 lang=cpp
 * @lcpr version=30204
 *
 * [303] Range Sum Query - Immutable
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
class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums):prefix(nums.size()) {
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int sum=0;
        if(left==0){
            sum = prefix[right];
        }else{
            sum = prefix[right] - prefix[left-1];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end



