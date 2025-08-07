/*
 * @lc app=leetcode.cn id=111 lang=cpp
 * @lcpr version=30204
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        // 迴圈解：BFS 適合用來找最短路徑（如最小深度），可以提早結束遍歷
        // 一層層走，碰到「第一個葉子節點」就是最短解
        if(!root) return 0;
        queue<TreeNode*> temp;
        int depth = 0;
        temp.push(root);
        while(!temp.empty()){
            //要記錄當前的隊列大小，才知道當層有幾個元素、彈出幾次
            int size = temp.size();
            depth++;
            while(size--){
                TreeNode* node = temp.front();
                temp.pop();
                //遇到葉子節點了，直接返回現在的深度
                if(!node->left && !node->right) return depth;
                if(node->left) temp.push(node->left);
                if(node->right) temp.push(node->right);
            }
        }
        return depth;
        // 遞迴解
        // if(!root) return 0;
        // int leftHeight = minDepth(root->left);
        // int rightHeight = minDepth(root->right);
        // // 如果其中一邊為空，必須走另一邊（不能直接取 min）
        // // 因為如果某個子樹為 nullptr，那條路不能算是從 root 到葉子的完整路徑
        // if (!root->left || !root->right) return leftHeight + rightHeight + 1;
        // return min(leftHeight, rightHeight)+1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,null,3,null,4,null,5,null,6]\n
// @lcpr case=end

 */

