/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30204
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        // 遞迴解：DFS 適合用來找最長路徑（如最大深度），一定要遍歷整棵樹
        // 要一路走到底（走到底的才有可能是最深的葉子）
        if(!root) return 0;
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return max(leftHeight, rightHeight)+1;
        // 迴圈解
        // if(!root) return 0;
        // queue<TreeNode*> temp;
        // int depth = 0;
        // temp.push(root);
        // while(!temp.empty()){
        //     //要記錄當前的隊列大小，才知道當層有幾個元素、彈出幾次
        //     int size = temp.size();
        //     depth++;
        //     while(size--){
        //         TreeNode* node = temp.front();
        //         temp.pop();
        //         if(node->left) temp.push(node->left);
        //         if(node->right) temp.push(node->right);
        //     }
        // }
        // return depth;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

