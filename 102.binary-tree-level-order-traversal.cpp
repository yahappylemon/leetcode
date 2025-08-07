/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30204
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(!root) return answer;
        queue<TreeNode*> temp;
        temp.push(root);
        while(!temp.empty()){
            //要記錄當前的隊列大小，才知道當層有幾個元素、彈出幾次
            int size = temp.size();
            vector<int> result;
            while(size--){
                TreeNode* node = temp.front();
                temp.pop();
                result.push_back(node->val);
                if(node->left) temp.push(node->left);
                if(node->right) temp.push(node->right);
            }
            answer.push_back(result);
        }
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

