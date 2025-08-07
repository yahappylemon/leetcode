/*
 * @lc app=leetcode.cn id=669 lang=cpp
 * @lcpr version=30204
 *
 * [669] Trim a Binary Search Tree
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
    // 前序遍歷效率較高，後序遍歷沒有剪枝，全部都要遍歷
    // leetcode沒有辦法寫主函數，重新賦值新的root，所以不能刪除
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;
        if(root->val<low){
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }else if(root->val>high){
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,2]\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,0,4,null,2,null,null,1]\n1\n3\n
// @lcpr case=end

 */

