/*
 * @lc app=leetcode.cn id=450 lang=cpp
 * @lcpr version=30204
 *
 * [450] Delete Node in a BST
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
    // 遞迴解：不換值（保留原值），把左樹移到右樹最小值(後繼節點)，用右樹取代刪除節點
    // TreeNode* deleteNode(TreeNode* root, int key) {
    //     // 第一种情况：没找到删除的节点
    //     if(!root) return root;
    //     if(root->val==key){
    //         // 第二种情况：左右孩子都为空（叶子节点）
    //         if(!root->left && !root->right){
    //             delete root;
    //             return nullptr;
    //         }
    //         // 第三种情况：左孩子为空，右孩子不为空
    //         else if(!root->left && root->right){
    //             TreeNode* temp=root;
    //             root=root->right;
    //             delete temp;
    //             return root;
    //         }
    //         // 第四种情况：右孩子为空，左孩子不为空
    //         else if(root->left && !root->right){
    //             TreeNode* temp=root;
    //             root=root->left;
    //             delete temp;
    //             return root;
    //         }
    //         // 第五种情况：左右孩子节点都不为空
    //         else{
    //             TreeNode* temp=root;
    //             TreeNode* cur=root->right;
    //             while(cur->left){
    //                 cur=cur->left;
    //             }
    //             // 左樹移到後繼節點
    //             cur->left=root->left;
    //             // 右樹取代刪除節點
    //             root=temp->right;
    //             delete temp;
    //             return root;
    //         }
    //     }
    //     if(root->val>key) root->left = deleteNode(root->left, key);
    //     if(root->val<key) root->right = deleteNode(root->right, key);
    //     return root;
    // }
    // 遞迴解：換值，用後繼節點取代刪除節點，需要再遞迴地刪除後繼節點
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val==key){
            // leaf node
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            // with one node
            else if(!root->left){
                TreeNode* node = root->right;
                delete root;
                return node;
            }
            else if(!root->right){
                TreeNode* node = root->left;
                delete root;
                return node;
            }
            // with two nodes
            else{
                TreeNode* suc=root->right;
                while(suc->left){
                    suc=suc->left;
                }
                root->val = suc->val;
                root->right = deleteNode(root->right, suc->val);
                return root;
            }
        }
        if(root->val>key) root->left=deleteNode(root->left, key);
        if(root->val<key) root->right=deleteNode(root->right, key);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,6,2,4,null,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,7]\n0\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */

