/*
 * @lc app=leetcode.cn id=3184 lang=cpp
 * @lcpr version=30204
 *
 * [3184] Count Pairs That Form a Complete Day I
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
    int countCompleteDayPairs(vector<int>& hours) {
        int pairs=0;
        for(int i=0;i<hours.size()-1;i++){
            for(int j=i+1;j<hours.size();j++){
                if((hours[i]+hours[j])%24==0){
                pairs++;
                }
            }
        }
        return pairs;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [12,12,30,24,24]\n
// @lcpr case=end

// @lcpr case=start
// [72,48,24,3]\n
// @lcpr case=end

 */

