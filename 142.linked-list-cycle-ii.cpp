/*
 * @lc app=leetcode.cn id=142 lang=cpp
 * @lcpr version=30204
 *
 * [142] Linked List Cycle II
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||head->next==nullptr) return nullptr;
        //設置快(一次走兩步)慢(一次走一步)指針
        ListNode* fast = head;
        ListNode* slow = head;
        //判斷鏈表是否有環：
        //當快指針不為空，向後尋找兩指針的相遇處
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                break;
            }
        }
        //跳出迴圈時fast是空指針代表沒有環
        if(fast==nullptr || fast->next==nullptr){
            return nullptr;
        }else{
            fast = head;
        }
        //找環的入口處：
        //頭節點=>環的入口處 = 兩指針相遇處=>環的入口處 的距離
        //兩指針分別從 頭節點 和 兩指針相遇處 開始走
        //相遇處即為環的入口處
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,0,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [1]\n-1\n
// @lcpr case=end

 */

