/*
 * @lc app=leetcode.cn id=3019 lang=cpp
 * @lcpr version=30204
 *
 * [3019] Number of Changing Keys
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
    int countKeyChanges(string s) {
        int changes=0;
        char pre,cur;
        int i=0,j=1;
        while(i<s.size()-1){
           pre= tolower(s[i]);
           cur= tolower(s[j]);
           if(pre!=cur) changes++;
            i=j;
            j++;
        }
        return changes;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aAbBcC"\n
// @lcpr case=end

// @lcpr case=start
// "AaAaAaaA"\n
// @lcpr case=end

 */

