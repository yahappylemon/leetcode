/*
 * @lc app=leetcode.cn id=541 lang=cpp
 * @lcpr version=30204
 *
 * [541] Reverse String II
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
    string reverse(string &s, int start, int end){
       while(start<end){
        char temp=s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
       }
        return s;
    }
    string reverseStr(string s, int k) {
        if(k==1) return s;
        if(k>=s.size()) return reverse(s, 0, s.size()-1);
        for(int i=0;i<s.size();i+=2*k){
            // 避免剩餘的字元不足，訪問越界
            if(i+k-1<s.size()){
            // reverse the first k characters
            // 情況1：every 2k characters
            // 情況2：less than 2k but greater than or equal to k characters
                reverse(s, i, i+k-1);
            }else{
                // reverse all of them(不足k，全部反轉)
                // 情況3：fewer than k characters left
                reverse(s, i, s.size()-1);
            }
        }
        
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */

