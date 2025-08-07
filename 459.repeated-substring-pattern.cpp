/*
 * @lc app=leetcode.cn id=459 lang=cpp
 * @lcpr version=30204
 *
 * [459] Repeated Substring Pattern
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
    bool repeatedSubstringPattern(string s) {
    //暴力解：O(n^2)
    //    for(int len=1;len<s.size();len++){
    //         string needle=string(s.begin(), s.begin()+len);
    //         int times = s.size()/len;
    //         string answer="";
    //         while(times--){
    //             answer+=needle;
    //         }
    //         if(answer==s) return true;
    //    }
    //     return false;
    //移動匹配：O(n)，取決於find()
    //如果一個字串 s 是由子字串重複組成的，
    //s + s 去掉第一個字元和最後一個字元後，
    //原本的 s 一定會在裡面出現一次
    //     string concat = s+s;
    //     concat.erase(concat.begin());
    //     concat.erase(concat.end()-1);
    //     if(concat.find(s)!=string::npos){
    //      return true;
    //     }else{
    //         return false;
    //     }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abab"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abcabcabcabc"\n
// @lcpr case=end

 */

