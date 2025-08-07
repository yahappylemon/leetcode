/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30204
 *
 * [28] Find the Index of the First Occurrence in a String
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
    // 暴力解：O(n*m)
    // int strStr(string haystack, string needle) {
    //     int slow = 0;
    //     int same=0;
    //     int index=INT_MAX;
    //     for(int fast=0; fast<haystack.size();fast++){
    //         if(haystack[fast]==needle[slow]){
    //             same++;
    //             if(slow==needle.size()-1){
    //                 int startIndex = fast-needle.size()+1;
    //                 index = min(startIndex, index);
    //                 break;
    //             }
    //             slow++;
    //         }else{
    //             //調整 fast 的位置到相同字串的起始點
    //             //fast++後，會從下一個字元開始
    //             fast = fast - same; 
    //             same=0;
    //             slow=0;
    //         }
    //     }
    //     return index==INT_MAX? -1:index;
    // }
    //精簡暴力解
    // int strStr(string haystack, string needle) {
    //     //最後一個合法的開頭出現在 haystack 長度 - needle長度 的字元
    //     for (int i = 0; i <= haystack.size() - needle.size(); i++) {
    //         int slow = 0;
    //         while (slow < needle.size() && haystack[i + slow] == needle[slow]) {
    //             slow++;
    //         }
    //         if (slow == needle.size()) return i;
    //     }
    //     return -1;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */

