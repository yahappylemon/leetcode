/*
 * @lc app=leetcode.cn id=654 lang=cpp
 * @lcpr version=30204
 *
 * [654] Maximum Binary Tree
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
        if(left>right) return nullptr;
        int max=INT_MIN;
        // 用left開頭，因為數組開頭不一定是0
        int index=left;
        // 用left開頭，因為數組開頭不一定是0
        // 用right結尾，因為數組結尾不一定是nums.size()-1
        for(int i=left;i<=right;i++){
            if(nums[i]>max){
                max=nums[i];
                index=i;
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left=buildTree(nums, left, index-1);
        root->right=buildTree(nums, index+1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
    // 複製新 vector：空間複雜度O(n log n)
    // TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //     if(nums.size()==0) return nullptr;
    //     int index=0;
    //     int max=INT_MIN;
    //     for(int i=0; i<nums.size();i++){
    //         if(nums[i]>max){
    //             max=nums[i];
    //             index=i;
    //         }
    //     }
    //     TreeNode* root = new TreeNode(max);
    //     if(nums.size()==1) return root;
    //     vector<int> left,right;
    //     for(int i=0; i<index;i++){
    //         left.push_back(nums[i]);
    //     }
    //     for(int i=index+1; i<nums.size();i++){
    //         right.push_back(nums[i]);
    //     }
    //     root->left=constructMaximumBinaryTree(left);
    //     root->right=constructMaximumBinaryTree(right);
    //     return root;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1,6,0,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */

