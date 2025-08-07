/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30204
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        if(!root) return answer;
        stack<TreeNode*> temp;
        temp.push(root);
        while(!temp.empty()){
            TreeNode* node = temp.top();
            temp.pop();
            answer.push_back(node->val);
            //先放入左子，彈出時才會先訪問右子
            if(node->left) temp.push(node->left);
            if(node->right) temp.push(node->right);
        }
        //數組中的順序是中右左，倒置後才會變左右中
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

