/*
 * @lc app=leetcode.cn id=2053 lang=cpp
 * @lcpr version=30204
 *
 * [2053] Kth Distinct String in an Array
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
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mymap;
        for(string words:arr){
            mymap[words]++;
        }
        for(string words:arr){
             if (mymap[words] == 1) {
                k--;
            }
            if (k == 0) {
                return words;
            }
        }
        return "";
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["d","b","c","b","c","a"]\n2\n
// @lcpr case=end

// @lcpr case=start
// ["aaa","aa","a"]\n1\n
// @lcpr case=end

// @lcpr case=start
// ["a","b","a"]\n3\n
// @lcpr case=end

 */

