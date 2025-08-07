/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30204
 *
 * [150] Evaluate Reverse Polish Notation
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
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int evaluation(int a, int b, string token){
        if(token=="+"){
            return a+b;
        }else if(token=="-"){
            return a-b;
        }else if(token=="*"){
            return a*b;
        }else{
            return a/b;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> temp;
        for(string token : tokens){
            if(token=="+"||token=="-"||token=="*"||token=="/"){
                int a = temp.top();
                temp.pop();
                int b = temp.top();
                temp.pop();
                int result = evaluation(b, a, token);
                temp.push(result);
            }else{
                temp.push(stoi(token));
            }
        }
        return temp.top();
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */

