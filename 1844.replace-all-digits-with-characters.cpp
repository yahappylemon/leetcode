/*
 * @lc app=leetcode.cn id=1844 lang=cpp
 * @lcpr version=30204
 *
 * [1844] Replace All Digits with Characters
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
    char shift(char c, int x){
        return char(c+x);
    }
    string replaceDigits(string s) {
        string output="";
        for(int i=0;i<s.size();i++){
            if(i%2==1){
                output+=shift(s[i-1],s[i]-'0');
            }else{
                output+=s[i];
            }
        }
        return output;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a1c1e1"\n
// @lcpr case=end

// @lcpr case=start
// "a1b2c3d4e"\n
// @lcpr case=end

 */

