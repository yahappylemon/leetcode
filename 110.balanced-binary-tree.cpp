/*
 * @lc app=leetcode.cn id=110 lang=cpp
 * @lcpr version=30204
 *
 * [110] Balanced Binary Tree
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
    // bottom-up寫法：O(n)，利用-1判斷是否已經不平衡，避免重複計算高度
    int getHeight(TreeNode* root){
        if(!root) return 0;
        int left = getHeight(root->left);
        if(left==-1) return -1;
        int right = getHeight(root->right);
        if(right==-1) return -1;
        if(abs(left-right)>1) return -1;
        else return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int result = getHeight(root);
        return result == -1 ? false: true;
    }
    // bottom-up寫法：O(n^2)
    // 先遞迴檢查子樹，再算高度差，每次重覆計算高度，但不平衡提早退出
    bool isBalance(TreeNode* root) {
        if(!root) return true;
        if (!isBalance(root->left)) return false;
        if (!isBalance(root->right)) return false;
        // 用一般的getHeight，不用-1判斷平衡
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return abs(left - right) <= 1;
    }
    // top-down寫法：O(n^2)
    // 先算高度差，再遞迴檢查子樹，每次重覆計算高度
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        // 用一般的getHeight，不用-1判斷平衡
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (abs(left - right) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

