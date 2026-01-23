/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

// @lc code=start
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
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot ||root->val != subRoot->val) return false;
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // include root && !subRoot and !root && !subRoot
        if(!subRoot) return true;
        // indicates subroot && !root
        if(!root) return false;
        // both root and subRoot exists
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
// @lc code=end

