/*
 * @lc app=leetcode.cn id=202 lang=cpp
 * @lcpr version=30204
 *
 * [202] Happy Number
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
    unordered_set<int> exist;
    bool isHappy(int n) {
        if(n==1) return true;
        if(exist.find(n)!=exist.end()){
                return false;
        }
        exist.insert(n);
        int sum=0;
        while(n>0){
            sum+=(n%10)*(n%10);
            n/=10;
       }
       return isHappy(sum);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 19\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

