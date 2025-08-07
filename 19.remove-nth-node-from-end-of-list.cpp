/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30204
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = dummyHead;
        ListNode* suc = dummyHead;
        //找正序第n個：讓suc和cur間隔n
        //當suc走到末尾時，cur剛好是倒數第n個節點
        for(int i=0;i<n;i++){
            suc=suc->next;
        }
        //三指標同時向後移動，suc到鏈表末尾停止
        //此時cur正好是倒數第n個節點
        while(suc!=nullptr){
            pre=cur;
            cur=cur->next;
            suc=suc->next;
        }
        ListNode* temp = cur;
        pre->next = cur->next;
        delete temp;
        temp = nullptr;
        head = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */

