/*
 * @lc app=leetcode.cn id=24 lang=cpp
 * @lcpr version=30204
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next=head;
        ListNode* cur = dummyHead;
        //偶數節點cur->next為空，奇數節點cur->next->next為空
        while(cur->next!=nullptr && cur->next->next!=nullptr){
            //第一個節點
            ListNode* pre = cur->next;
            //第二個節點的下一個節點
            ListNode* suc = cur->next->next->next;
            //第一個節點的前一個節點 指向 第二個節點
            cur->next = cur->next->next;
            //第二個節點 指向 第一個節點
            cur->next->next = pre;
            //第一個節點 指向 第二個節點的下一個節點
            pre->next = suc;
            //cur往後移動兩格(下一輪交換中第一個節點的前一個節點)
            cur = cur->next->next;
        }
        head=dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */

