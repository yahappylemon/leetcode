/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30204
 *
 * [98] Validate Binary Search Tree
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
#include <set>
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
    // 中序遍歷：使用額外容器，走完才比較
    // vector<int> inorder(TreeNode* root, vector<int> &current){
    //     if(!root) return current;
    //     inorder(root->left, current);
    //     current.push_back(root->val);
    //     inorder(root->right, current);
    //     return current;
    // }
    // bool isValidBST(TreeNode* root) {
    //     vector<int> traversal;
    //     traversal=inorder(root, traversal);
    //     for(int i=0;i<traversal.size()-1;i++){
    //         if(traversal[i]>=traversal[i+1]) return false;
    //     }
    //     return true;
    // }
    // 雙指針法：不使用額外容器，邊走邊比較 
    bool inorder(TreeNode* root, TreeNode* &pre) {
        if(!root) return true;
        bool left = inorder(root->left,pre);
        // 一旦出現前一個值>=當前值的情況就返回
        if(pre && pre->val>=root->val){
            return false;
        }else{
            pre = root;
        }
        bool right = inorder(root->right,pre);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        // 紀錄前一個節點的值   
        TreeNode* pre=nullptr;
        return inorder(root, pre);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

