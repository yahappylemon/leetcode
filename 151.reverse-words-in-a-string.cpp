/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30204
 *
 * [151] Reverse Words in a String
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
#include <sstream>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    //時間複雜度：O(n)，空間複雜度：O(1)(in-place)
    string reverseWords(string &s) {
        //移除多餘的空格(相當於數組移除元素)
        int slow=0;
        for(int fast=0; fast<s.size();fast++){
            //單字開頭：快指針遇到新單字才會進入
            if(s[fast]!=' '){
                //加入空格：除了第一個單詞以外，要先加上空格
                if(slow!=0) {
                    s[slow] = ' ';
                    slow++;
                }
                //單字結尾：直到快指針遇到空格，進入下個單字
                while(fast<s.size() && s[fast]!=' '){
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
            }
        }
        // 重置字串大小
        s.resize(slow);

        //將整個字符串反轉
        reverse(s.begin(),s.end());

        //將個別單字反轉為正序
        //單字開頭
        int k = 0;
        for(int i=0; i<=s.size();i++){
            //走到空格或字串末尾：單字結尾
            if(s[i]==' '||i==s.size()){
                reverse(s.begin()+k, s.begin()+i);
                //更新為下一個單字的開頭
                k=i+1;
            }
        }
        return s;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */

