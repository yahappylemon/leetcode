/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30204
 *
 * [101] Symmetric Tree
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEqual(TreeNode* left, TreeNode* right){
        if(!left && !right ) return true;
        if(!left && right) return false;
        if(left && !right) return false;
        if(left->val != right->val) return false;
        bool outside = isEqual(left->left, right->right);
        bool inside = isEqual(left->right, right->left);
        return outside && inside;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isEqual(root->left, root->right);
    }
    // 補null才能顯示出樹的結構，而且只有前、後序遍歷才能唯一還原整棵樹
    // 因為前、後序可以表示「父子結構」、分辨null 屬於哪個子樹
    // vector<int> postorder(vector<int> &answer, TreeNode* root){
    //     if(!root) {
    //         answer.push_back(INT_MIN);
    //         return answer;
    //     }
    //     postorder(answer, root->left);
    //     postorder(answer, root->right);
    //     answer.push_back(root->val);
    //     return answer;
    // }
    // vector<int> r_postorder(vector<int> &answer, TreeNode* root){
    //     if(!root) {
    //         answer.push_back(INT_MIN);
    //         return answer;
    //     }
    //     r_postorder(answer, root->right);
    //     r_postorder(answer, root->left);
    //     answer.push_back(root->val);
    //     return answer;
    // }
    // bool isSymmetric(TreeNode* root) {
    //     if(!root|| !root->left && !root->right) return true;
    //     if(!root->left && root->right) return false;
    //     if(root->left && !root->right) return false;
    //     if(root->left->val!=root->right->val) return false;
    //     vector<int> lefttree,righttree;
    //     postorder(lefttree, root->left);
    //     r_postorder(righttree, root->right);
    //     return lefttree==righttree;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */

