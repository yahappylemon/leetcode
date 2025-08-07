/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30204
 *
 * [21] Merge Two Sorted Lists
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr && list2==nullptr) return nullptr;
        if(list1!=nullptr && list2==nullptr) return list1;
        if(list1==nullptr && list2!=nullptr) return list2;
        ListNode* i = list1;
        ListNode* j = list2;
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        while(i && j){
            if(i->val <= j->val){
                cur->next = i;
                i = i->next;
                cur=cur->next;
            }else{
                cur->next = j;
                j = j->next;
                cur=cur->next;
            }
        }
        if(i){
            cur->next = i;
        }
        if(j){
            cur->next = j;
        }
        return dummyHead->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */

