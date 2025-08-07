/*
 * @lc app=leetcode.cn id=700 lang=cpp
 * @lcpr version=30204
 *
 * [700] Search in a Binary Search Tree
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
// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };


class Solution {
public:
    // 遞迴解
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val==val) return root;
        else if(root->val>val) return searchBST(root->left,val); 
        else return searchBST(root->right, val);
    }
    // 迴圈解
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     while(root!=nullptr){
    //         if(root->val>val){
    //             root=root->left;
    //         }else if(root->val<val){
    //             root=root->right;
    //         }else{
    //             return root;
    //         }
    //     }
    //     return nullptr;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,1,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,7,1,3]\n5\n
// @lcpr case=end

 */

