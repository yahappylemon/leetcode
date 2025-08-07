/*
 * @lc app=leetcode.cn id=278 lang=cpp
 * @lcpr version=30204
 *
 * [278] First Bad Version
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
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long left=1;
        long long right=n;
        long long first=n;
        while(left<=right){
            long long mid = (left+right)/2;
            if(isBadVersion(mid)){
                if(mid<=first){
                    first=mid;
                    right = mid-1;
                }
            }else if(!isBadVersion(mid)){
                left=mid+1;
            }
        }
        return first;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n4\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */

