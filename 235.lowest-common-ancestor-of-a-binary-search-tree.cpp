/*
 * @lc app=leetcode.cn id=235 lang=cpp
 * @lcpr version=30204
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // 遞迴版本
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        // 自己是其中一個節點
        if(root==p||root==q) return root;
        // 出現在左子樹，往左找(left && !right)
        if(root->val>p->val && root->val>q->val){
           return lowestCommonAncestor(root->left, p, q);
        }
        // 出現在右子樹，往右找(!left && right)
        if(root->val<p->val && root->val<q->val){
           return lowestCommonAncestor(root->right, p, q);
        }
        // 一大一小，返回root(left && right)
        return root;
    }
    // 迴圈版本
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     while(root){
    //         // 出現在左子樹，往左找
    //         if(root->val>p->val && root->val>q->val){
    //             root=root->left;
    //         }
    //         // 出現在右子樹，往右找
    //         else if(root->val<p->val && root->val<q->val){
    //             root=root->right;
    //         }else{
    //             return root;
    //         }
    //     }
    //     return nullptr;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
// @lcpr case=end

// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n1\n
// @lcpr case=end

 */

