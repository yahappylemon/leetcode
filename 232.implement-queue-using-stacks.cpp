/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * @lcpr version=30204
 *
 * [232] Implement Queue using Stacks
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
class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    MyQueue() {

    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        //只有out為空，才需要搬移資料
        if(out.empty()){
            while(!in.empty()){
                int temp = in.top();
                out.push(temp);
                in.pop();
            }
        }
        int answer = out.top();
        out.pop(); 
        return answer;
    }
    
    int peek() {
        //從out取出元素，要放回out堆疊
        int result = this->pop();
        out.push(result);
        return result;
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end



