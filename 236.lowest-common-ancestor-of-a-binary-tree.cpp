/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30204
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
    // 後序遍歷 + 利用回傳值判斷子樹是否找到：O(n)
    // 用後序遍歷，因為要先得到左右子的結果再向上回傳
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root==p||root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 左右返回的結果都是已經找到，代表自己就是最近公共祖先
        if(left && right) return root;
        // 只有左邊或右邊有找到，向上傳遞有找到的結果
        else if(left && !right) return left;
        else if(!left && right) return right;
        else return nullptr;
    }
    // 後序遍歷 + 檢查當前節點是否同時包含 p 和 q：O(n^2)
    // 用後序遍歷，因為先遍歷到root的話不是最近公共祖先
    // bool findleaf(TreeNode* root, int target){
    //     if(!root) return false;
    //     if(root->val==target) return true;
    //     bool left = findleaf(root->left, target);
    //     bool right = findleaf(root->right, target);
    //     return left||right;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if(!root) return nullptr; 
    //     TreeNode* left = lowestCommonAncestor(root->left,p,q);
    //     // 已經找到最近公共節點，直接返回
    //     if(left) return left;
    //     TreeNode* right = lowestCommonAncestor(root->right,p,q);
    //     if(right) return right;
    //     if(findleaf(root, p->val) && findleaf(root, q->val)){
    //        return root;
    //     }
    //     return nullptr;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */

