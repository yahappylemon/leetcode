/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30204
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        int counta=0, countb=0;
        int gap=0;
        //計算兩鏈表長度
        while(a){
            counta++;
            a=a->next;
        }
        while(b){
            countb++;
            b=b->next;
        }
        //重置頭節點
        a = headA;
        b = headB;
        //讓較長的鏈表先往前走差距的步數
        //因為兩鏈表如果有相交，代表差距只在相交前的節點個數
        //同時移動時就能走到相交的節點
        if(counta>countb){
            gap=counta-countb;
            while(gap--){
                a=a->next;
            }
        }else{
            gap=countb-counta;
            while(gap--){
                b=b->next;
            }
        }
        while(a!=nullptr && b!=nullptr){
            if(a==b){
                return a;
            }
            a=a->next;
            b=b->next;
        }
        return nullptr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */

