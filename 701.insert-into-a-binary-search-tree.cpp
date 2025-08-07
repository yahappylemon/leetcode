/*
 * @lc app=leetcode.cn id=701 lang=cpp
 * @lcpr version=30204
 *
 * [701] Insert into a Binary Search Tree
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
    // 遞迴解
    // TreeNode* insertIntoBST(TreeNode* root, int val){
    //     if(!root) return new TreeNode(val);
    //     if(root->val>val) root->left=insertIntoBST(root->left, val);
    //     if(root->val<val) root->right=insertIntoBST(root->right, val);
    //     return root;
    // }
    // 迴圈解
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(!root) return node;
        TreeNode* cur = root;
        while(cur){
            if(cur->val>val){
                // 找到葉子節點，可以插入
                if(!cur->left){
                    cur->left=node;
                    break;
                }
                cur=cur->left;
            }else{
                // 找到葉子節點，可以插入
                if(!cur->right){
                    cur->right=node;
                    break;
                }
                cur=cur->right;
            }
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [40,20,60,10,30,50,70]\n25\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3,null,null,null,null,null,null]\n5\n
// @lcpr case=end

 */

