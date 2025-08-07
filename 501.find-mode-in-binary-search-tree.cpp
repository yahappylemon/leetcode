/*
 * @lc app=leetcode.cn id=501 lang=cpp
 * @lcpr version=30204
 *
 * [501] Find Mode in Binary Search Tree
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
    // 使用map紀錄所有節點出現的頻率：如果不是BST只能用此法
    // void inorder(TreeNode* root, unordered_map<int,int> &map){
    //     if(!root) return;
    //     inorder(root->left, map);
    //     map[root->val]++;
    //     inorder(root->right, map);
    // }
    // bool static cmp(const pair<int,int> &a,const pair<int,int> &b){
    //     return a.second>b.second;
    // }
    // vector<int> findMode(TreeNode* root){
    //     vector<int> result;
    //     if(!root) return result;
    //     unordered_map<int,int> map;
    //     inorder(root, map);
    //     // 遍歷找最大值：O(n)，只想找出所有最大值對應的 key
    //     int max=INT_MIN;
    //     for(pair<int, int> i:map){
    //         if(i.second>max){
    //             // 將之前的結果清空
    //             result.clear();
    //             max=i.second;
    //             result.push_back(i.first);
    //         }else if(i.second==max){
    //             result.push_back(i.first);
    //         }
    //     }
    //     // 排序找最大值：O(n log n)，對整體 key-value 做排名
    //     // 先轉換成vector才能針對value進行排序
    //     // vector<pair<int,int>> arr(map.begin(),map.end());
    //     // sort(arr.begin(),arr.end(),cmp);
    //     // result.push_back(arr[0].first);
    //     // // 如果有與最高值相同的也插入
    //     // for(int i=1;i<arr.size();i++){
    //     //     if(arr[i].second==arr[0].second) result.push_back(arr[i].first);
    //     //     else break;
    //     // }
    //     return result;
    // }
    // 雙指針法：O(n)，BST適用
    // 因為中序遍歷的結果是排序好的，相同值會連續出現
    vector<int> modes;
    int max=INT_MIN;
    void inorder(TreeNode* root,TreeNode* &pre, int &count){
        if(!root) return;
        inorder(root->left, pre, count);
        if(pre && pre->val==root->val){
            count++;
            pre=root;
        }else{
            count=1;
            pre=root;
        }
        // 兩遍法（Two-Pass Solution）：先跑一次統計資訊，再跑一次拿到答案
        // 第一次遍歷：用vector<pair<int, int>>紀錄出現數字及頻率，找出最大頻率
        // 第二次遍歷：找出所有等於最大頻率的數字
        // 一遍法（One-pass solution）：在一個迴圈中就完成資訊收集與結果處理
        if(count>max){
            // 將之前的結果清空
            modes.clear();
            max=count;
            modes.push_back(root->val);
        }else if(count==max){
            modes.push_back(root->val);
        }
        inorder(root->right, pre, count);
    }
    vector<int> findMode(TreeNode* root) {
        if(!root) return {0};
        TreeNode* pre=nullptr;
        int count=1;
        inorder(root, pre, count);
        return modes;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

