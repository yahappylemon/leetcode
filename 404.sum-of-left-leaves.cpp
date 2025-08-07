/*
 * @lc app=leetcode.cn id=404 lang=cpp
 * @lcpr version=30204
 *
 * [404] Sum of Left Leaves
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
    int collectLeaves(TreeNode* root, int &count){
        if(!root) return count;
        if(!root->left && !root->right) return count;
        if(root->left){
            if(!root->left->left && !root->left->right){
                count+=root->left->val;
            }else{
                collectLeaves(root->left,count);
            }
        }
        if(root->right){
            collectLeaves(root->right,count);
        }
        return count;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int count=0;
        int result = collectLeaves(root, count);
        return count;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

