/*
 * @lc app=leetcode.cn id=2150 lang=cpp
 * @lcpr version=30204
 *
 * [2150] Find All Lonely Numbers in the Array
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
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mymap;
        vector<int> answer;
        for(int i:nums){
            mymap[i]++;
        }
        for(int i:nums){
            if(mymap[i]==1&&mymap[i-1]==0&&mymap[i+1]==0){
                answer.push_back(i);
            }
        }
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,6,5,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,3]\n
// @lcpr case=end

 */

