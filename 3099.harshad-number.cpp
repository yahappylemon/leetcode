/*
 * @lc app=leetcode.cn id=3099 lang=cpp
 * @lcpr version=30204
 *
 * [3099] Harshad Number
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
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum=0;
        int initial = x;
        while(x>0){
            sum+=x%10;
            x/=10;
        }
        return initial%sum==0?sum:-1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 18\n
// @lcpr case=end

// @lcpr case=start
// 23\n
// @lcpr case=end

 */

