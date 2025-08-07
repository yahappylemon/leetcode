/*
 * @lc app=leetcode.cn id=513 lang=cpp
 * @lcpr version=30204
 *
 * [513] Find Bottom Left Tree Value
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
    // 迴圈版：層序遍歷(BFS)
    int findBottomLeftValue(TreeNode* root) {
        int result=0;
        if(!root) return result;
        queue<TreeNode*> temp;
        temp.push(root);
        while(!temp.empty()){
            int size = temp.size();
            // 每層的第一個節點就是當層最左邊的值
            TreeNode* leftNode = temp.front();
            result = leftNode->val;
            while(size--){
                TreeNode* current = temp.front();
                temp.pop();
                if(current->left){
                    temp.push(current->left);
                }
                if(current->right){
                    temp.push(current->right);
                }
            }
        }
        return result;
    }
    // 遞迴版：深度優先遍歷(DFS)
    // int maxDepth = INT_MIN;
    // int result=0;
    // void getLeft(TreeNode* root, int depth){
    //     if(!root) return;
    //     // 遇到葉子節點，比較深度，較深則更新深度值及節點值
    //     if(!root->left && !root->right){
    //         if(depth>maxDepth){
    //             maxDepth = depth;
    //             result = root->val;
    //         }
    //         return;
    //     }
    //     // 因為先做左邊，右節點相同深度不會更新result
    //     if(root->left) getLeft(root->left, depth+1);
    //     if(root->right) getLeft(root->right, depth+1);
    // }
    // int findBottomLeftValue(TreeNode* root){
    //     if(!root) return result;
    //     getLeft(root, 0);
    //     return result;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,5,6,null,null,7]\n
// @lcpr case=end

 */

