/*
 * @lc app=leetcode.cn id=257 lang=cpp
 * @lcpr version=30204
 *
 * [257] Binary Tree Paths
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <string>
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
    vector<string> answer;
    void findPath(string path, TreeNode* root){
        if(!root) return;
        // 前序遍歷：加上當前節點值
        path += to_string(root->val);
        // 是葉節點，直接加入結果
        if(!root->left && !root->right){
            answer.push_back(path);
            return;
        }
        // 不是葉子，繼續向下遞迴
        // 要確保每次函數調用後，path依然是"父節點->"
        // 方式一：用 path + "->" 傳新值，每次都是新副本
        if (root->left) findPath(path + "->", root->left);
        if (root->right) findPath(path + "->", root->right);
        // 方式二：在 if 前+= "->"，只修改本層副本一次	
        // 只做一次+= "->"，同一個 path 傳給左右子節點
        // 左右子樹看到的是一樣的 "父節點->" 的 path
        // 即使 path 在遞迴時被改變，也不會影響外層的狀態
        // path += "->";
        // if (root->left) findPath(path, root->left);
        // if (root->right) findPath(path, root->right);
        // 錯誤版本：在 if 內部+= "->"，會重複修改本層副本	
        // 第一次進 if (root->left) 時，做一次path+="->"，變成"父節點->"
        // 第二次進 if (root->right) 時，又對同一個 path 副本做一次+="->"，變成"父節點->->" 
        // if (root->left) {
        //     path += "->";
        //     findPath(path, root->left);
        // }
        // if (root->right) {
        //     path += "->";
        //     findPath(path, root->right);
        // }
    }    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return answer;
        findPath("", root);
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

