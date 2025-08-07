/*
 * @lc app=leetcode.cn id=530 lang=cpp
 * @lcpr version=30204
 *
 * [530] Minimum Absolute Difference in BST
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
    // vector<int> inorder(TreeNode* root, vector<int> &arr){
    //     if(!root) return arr;
    //     inorder(root->left, arr);
    //     arr.push_back(root->val);
    //     inorder(root->right, arr);
    //     return arr;
    // }
    // int getMinimumDifference(TreeNode* root) {
    //     vector<int> arr;
    //     arr = inorder(root, arr);
    //     int minimum= abs(arr[1]-arr[0]);
    //     for(int i=0;i<arr.size()-1;i++){
    //         if(abs(arr[i]-arr[i+1])<min){
    //             minimum=abs(arr[i]-arr[i+1]);
    //         }
    //     }
    //     return minimum;
    // }
    int inorder(TreeNode* root,TreeNode* &pre, int &minimum){
        if(!root) return minimum;
        int left = inorder(root->left, pre, minimum);
        if(pre && abs(root->val-pre->val)<minimum){
            minimum=abs(root->val-pre->val);
        }
        pre=root;
        int right = inorder(root->right, pre, minimum);
        return min(left,right);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode* pre=nullptr;
        int minimum=INT_MAX;
        minimum = inorder(root, pre, minimum);
        return minimum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,6,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */

