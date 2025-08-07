/*
 * @lc app=leetcode.cn id=108 lang=cpp
 * @lcpr version=30204
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    // 使用區間索引：空間複雜度O(log n)
    TreeNode* buildTree(vector<int>& nums, int left, int right){
        // 索引越界
        if(left>right) return nullptr;
        // 避免overflow
        // mid = left + (right - left) / 2  
        //     = left + (right/2 - left/2)  
        //     = (2*left + right - left) / 2  
        //     = (left + right) / 2
        int mid = left+((right-left)/2);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, left, mid-1);
        root->right = buildTree(nums, mid+1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
    // 複製新 vector：空間複雜度O(n log n)
    // TreeNode* sortedArrayToBST(vector<int>& nums) {
    //     if(nums.size()==0) return nullptr;
    //     int index = nums.size()/2;
    //     TreeNode* root = new TreeNode(nums[index]);
    //     vector<int> left=vector(nums.begin(),nums.begin()+index);
    //     vector<int> right=vector(nums.begin()+index+1,nums.end());
    //     root->left = sortedArrayToBST(left);
    //     root->right = sortedArrayToBST(right);
    //     return root;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */

