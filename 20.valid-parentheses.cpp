/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <sstream>
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
    bool isValid(string s) {
        stack<char> temp;
        for(char i : s){
            if(i==')'){
                //有多餘的右括號||左右括號不匹配
                if(temp.empty()||temp.top()!='(') return false;
                temp.pop();
            }else if(i=='}'){
                if(temp.empty()||temp.top()!='{') return false;
                temp.pop();
            }else if(i==']'){
                if(temp.empty()||temp.top()!='[') return false;
                temp.pop();
            }else{
                //也可以在入棧時放入相對應的右括號，這樣匹配時就可以直接比對
                temp.push(i);
            }
        }
        //有多餘的左括號
        return temp.empty();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */

