/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30204
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 空節點
        if(postorder.size()==0) return nullptr;
        // 後序遍歷最後一個節點是根節點
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        // 只剩一個節點代表是葉子節點，返回結果
        if(postorder.size()==1) return root;
        // 利用根節點在中序遍歷索引，切割出中序左子樹和中序右子樹
        int index = 0;
        for(index; index<inorder.size();index++){
            if(inorder[index]==root->val){
                break;
            }
        }
        vector<int> leftInorder, rightInorder;
        for(int i=0; i<index;i++){
            leftInorder.push_back(inorder[i]);
        }
        for(int i=index+1; i<inorder.size();i++){
            rightInorder.push_back(inorder[i]);
        }
        // 利用中序左子樹和中序右子樹長度，切割出後序左子樹和後序右子樹
        vector<int> leftPostorder, rightPostorder;
        for(int i=0;i<leftInorder.size();i++){
            leftPostorder.push_back(postorder[i]);
        }
        for(int i=leftInorder.size();i<leftInorder.size()+rightInorder.size();i++){
            rightPostorder.push_back(postorder[i]);
        }
        // 持續遞迴
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

