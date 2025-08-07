/*
 * @lc app=leetcode.cn id=2828 lang=cpp
 * @lcpr version=30204
 *
 * [2828] Check if a String Is an Acronym of Words
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
#include <sstream>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string test="";
        string temp="";
        for(int i=0;i<words.size();i++){
            test+=words[i][0];
        }
        return test==s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["alice","bob","charlie"]\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// ["an","apple"]\n"a"\n
// @lcpr case=end

// @lcpr case=start
// ["never","gonna","give","up","on","you"]\n"ngguoy"\n
// @lcpr case=end

 */

