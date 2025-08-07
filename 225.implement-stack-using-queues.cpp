/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30204
 *
 * [225] Implement Stack using Queues
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
class MyStack {
public:
    //主容器：功能為放入新的元素
    queue<int> in;
    //暫時容器：功能為找出最後一個元素，暫時存放其他元素，最後要再放回in
    queue<int> out;
    MyStack() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        //使用兩個隊列
        //從in找到最後一個元素(size-1)
        //其他元素搬移到out
        // int size = in.size();
        // size--;
        // while(size--){
        //     out.push(in.front());
        //     in.pop();
        // }
        // int answer = in.front();
        // in.pop();
        // //把out的元素再搬回in
        // in=out;
        // //清空out隊列
        // while(!out.empty()){
        //     out.pop();
        // }

        // 只用一個隊列
        // 找到最後一個元素(size-1)
        // 把最後一個元素之前的元素再加入隊列後方
        int size = in.size();
        size--;
        while(size--){
            in.push(in.front());
            in.pop();
        }
        int answer = in.front();
        in.pop();
        return answer;
    }
    
    int top() {
        // 使用兩個隊列
        // 從in找到最後一個元素(size-1)
        // 其他元素搬移到out
        //    int size = in.size();
        //     size--;
        //     while(size--){
        //         out.push(in.front());
        //         in.pop();
        //     }
        //     int answer = in.front();
        //     out.push(answer);
        //     in.pop();
        // // 把out的元素再搬回in
        //     in=out;
        // //清空out隊列
        //     while(!out.empty()){
        //         out.pop();
        //     }
        //     return answer;
        // 只用一個隊列
        return in.back();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end



