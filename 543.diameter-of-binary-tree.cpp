/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int maxD = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        getHeight(root);
        return maxD;
    }
    int getHeight(TreeNode* root){
        if(!root) return 0;
        int LH=0;
        int RH=0;
        if(root->left) LH = getHeight(root->left);
        if(root->right) RH = getHeight(root->right);
        maxD = max(maxD, LH+RH);
        return max(LH,RH)+1;
    }
};
// @lc code=end

