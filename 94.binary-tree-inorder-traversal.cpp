/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30204
 *
 * [94] Binary Tree Inorder Traversal
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

//  if(root!=nullptr){
//     inorderTraversal(root->left);
//     output.push_back(root->val);
//     inorderTraversal(root->right);
// }
class Solution {
public:
//另一種寫法：使用boolean標記節點是否訪問過，true代表可以打印了
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> answer;
   if(!root) return answer;
   stack<TreeNode*> temp;
   TreeNode* current = root;
   	//中序遍歷造訪、處理節點順序與前後序不同，不能直接入棧彈出
    //(中間節點先造訪，但還沒要打印)
	//不能只用!temp.empty()當判斷條件，因為棧一開始為空，不會進入
	//不能只用current!=nullptr當判斷條件，current走到底或右子節點為空變成 nullptr
    //要繼續回溯temp內部的其他節點
    while(current!=nullptr||!temp.empty()){
        //一直往左走，直到找到第一個要遍歷的最左節點
        while(current!=nullptr){
            temp.push(current);
            current=current->left;
        }
        //current為空，彈出要處理的節點
        current=temp.top();
        temp.pop();
        answer.push_back(current->val);
        current=current->right;
    }
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

