/*
 * @lc app=leetcode.cn id=538 lang=cpp
 * @lcpr version=30204
 *
 * [538] Convert BST to Greater Tree
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
    // 反中序遍歷(右中左)：O(n)，只要遍歷一次樹
    void convert(TreeNode* root, int &pre){
        if(!root) return;
        convert(root->right, pre);
        pre+=root->val;
        root->val = pre;
        convert(root->left, pre);
    }
    TreeNode* convertBST(TreeNode* root) {
        int pre=0;
        convert(root, pre);
        return root;
    }
    // 中序遍歷(左中右)：O(2n)要先遍歷一次樹求總和
    // int TreeSum(TreeNode* root, int sum){
    //     if(!root) return 0;
    //     int leftSum=TreeSum(root->left, sum);
    //     int rightSum=TreeSum(root->right, sum);
    //     return leftSum+rightSum+root->val;

    // }
    // void convert(TreeNode* root, int total, int &leftSum){
    //     if(!root) return;
    //     convert(root->left, total, leftSum);
    //     int initial = root->val;
    //     root->val=total-leftSum;
    //     leftSum+=initial;
    //     convert(root->right, total, leftSum);
    // }
    // TreeNode* convertBST(TreeNode* root) {
    //    int total = TreeSum(root, 0);
    //    int leftSum=0;
    //    convert(root, total, leftSum);   
    //    return root;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n
// @lcpr case=end

// @lcpr case=start
// [0,null,1]\n
// @lcpr case=end

 */

