/*
 * @lc app=leetcode.cn id=112 lang=cpp
 * @lcpr version=30204
 *
 * [112] Path Sum
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
    // 扣除法
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     if(!root) return false;
    //     // 前序遍歷：扣除當前節點值
    //     targetSum-=root->val;
    //     // 是葉節點，判斷扣除當前節點值後是否與目標值相同
    //     if(!root->left && !root->right){
    //         return targetSum==0;
    //     }
    //      // 不是葉子，繼續向下遞迴
    //      // 要確保每次函數調用後，targetSum仍為原本的目標值
    //      // 即使 targetSum 在遞迴時被改變，也不會影響外層的狀態
    //     return hasPathSum(root->left, targetSum)||hasPathSum(root->right, targetSum);
    // }
    // 累加法
    bool root_to_leaf(TreeNode* root, int cursum, int targetSum) {
        if(!root) return false;
        // 前序遍歷：加上當前節點值
        cursum+=root->val;
        // 是葉節點，判斷當前累加值是否與目標值相同
        if(!root->left && !root->right){
            return targetSum==cursum;
        }
        // 不是葉子，繼續向下遞迴
        // 要確保每次函數調用後，cursum仍為原本的累加值
        // 即使 cursum 在遞迴時被改變，也不會影響外層的狀態
        return root_to_leaf(root->left,cursum, targetSum)||root_to_leaf(root->right,cursum, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return root_to_leaf(root, 0, targetSum);
    }
    // 依照257題思路，找出所有路徑後判斷有無符合目標值
    // vector<int> answer;
    // void root_to_leaf(TreeNode* root, int sum){
    //     if(!root) return;
    //     // 前序遍歷：加上當前節點值
    //     sum+=root->val;
    //     // 是葉節點，直接加入結果
    //     if(!root->left && !root->right) {
    //         answer.push_back(sum);
    //         return;
    //     }
    //      // 不是葉子，繼續向下遞迴
    //     if(root->left)  root_to_leaf(root->left, sum);
    //     if(root->right)  root_to_leaf(root->right, sum);
    // }
    // bool hasPathSum(TreeNode* root, int targetSum) {
    //     root_to_leaf(root, 0);
    //     for(int i:answer){
    //         if(i==targetSum){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,null,1]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

