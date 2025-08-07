/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool preorder(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if((p && !q) || (!p && q)) return false;
        if(p->val != q->val) return false;

        bool left = preorder(p->left, q->left);
        bool right = preorder(p->right, q->right);

        return left && right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorder(p, q);
    }
};
// @lc code=end

