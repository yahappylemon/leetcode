/*
 * @lc app=leetcode.cn id=2315 lang=cpp
 * @lcpr version=30204
 *
 * [2315] Count Asterisks
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
    int countAsterisks(string s) {
        int num=0;
        for(int i=0; i<s.size();i++){
            if(s[i]=='|'){
                i+=1;
                while(s[i]!='|'){
                    i++;
                }
                continue;
            }
            if(s[i]=='*'){
                num++;
            }
        }
        return num;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "l|*e*et|c**o|*de|"\n
// @lcpr case=end

// @lcpr case=start
// "iamprogrammer"\n
// @lcpr case=end

// @lcpr case=start
// "yo|uar|e**|b|e***au|tifu|l"\n
// @lcpr case=end

 */

