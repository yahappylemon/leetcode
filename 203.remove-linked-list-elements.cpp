// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 * @lcpr version=30204
 *
 * [203] Remove Linked List Elements
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
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
    //直接使用原来的链表来进行移除节点操作
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
        //delete head
        //use while not if to delete continuous heads
        while(head!=nullptr && head->val==val){
            ListNode* temp = head;
            head=head->next;
            delete temp;
        }
        // 從新的 head 開始處理
        ListNode* cur = head;
        //delete non-head
        while(cur!=nullptr && cur->next!=nullptr){
            if(cur->next->val==val){
                ListNode* temp = cur->next;
                cur->next=cur->next->next;
                delete temp;
            }else{
                cur=cur->next;
            }
        }
        return head;
    }
    //设置一个虚拟头结点在进行移除节点操作
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyhead = new ListNode();
        dummyhead->next=head;
        ListNode* cur = dummyhead;
        while(cur->next!=nullptr){
            if(cur->next->val==val){
                ListNode* temp = cur->next;
                cur->next=cur->next->next;
                delete temp;
            }else{
                cur=cur->next;
            }
        }
        head = dummyhead->next;
        delete dummyhead;
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,6,3,4,5,6]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n7\n
// @lcpr case=end

 */

