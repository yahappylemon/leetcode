/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30204
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size()==1) return root;

        int index=0;
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

        vector<int> leftPreorder, rightPreorder;
        for(int i=1; i<leftInorder.size()+1;i++){
            leftPreorder.push_back(preorder[i]);
        }
        for(int i=leftInorder.size()+1; i<leftInorder.size()+rightInorder.size()+1;i++){
            rightPreorder.push_back(preorder[i]);
        }

        root->left=buildTree(leftPreorder, leftInorder);
        root->right=buildTree(rightPreorder,rightInorder);
        return root;       
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */

