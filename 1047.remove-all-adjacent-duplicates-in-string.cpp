/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=30204
 *
 * [1047] Remove All Adjacent Duplicates In String
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
    string removeDuplicates(string s) {
        //與括號匹配是同樣的概念，都是要檢查相鄰元素
        //也可以使用字符串取代stack，最後就不用反轉
        stack<char> temp;
        string answer="";
        for(char i:s){
            if(temp.empty()||temp.top()!=i){
                temp.push(i);             
            }else{
                temp.pop();
                continue;
            }
        }
        while(!temp.empty()){
            answer+=temp.top();
            temp.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

// @lcpr case=start
// "azxxzy"\n
// @lcpr case=end

 */

