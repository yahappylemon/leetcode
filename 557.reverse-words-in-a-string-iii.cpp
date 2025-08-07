/*
 * @lc app=leetcode.cn id=557 lang=cpp
 * @lcpr version=30204
 *
 * [557] Reverse Words in a String III
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
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int start=0;
        for(int i=0;i<=s.size();i++){
            if(s[i]==' '||i==s.size()){
                reverse(s.begin()+start, s.begin()+i);
                start = i+1;
            }
        }
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "Let's take LeetCode contest"\n
// @lcpr case=end

// @lcpr case=start
// "Mr Ding"\n
// @lcpr case=end

 */

