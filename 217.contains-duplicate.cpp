/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
// Time: O(n)，出現重複提早退出；space: O(n)
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<=1) return false;
        unordered_set<int> seen;
        for(int i=0;i<nums.size();i++){
            if(seen.find(nums[i])!=seen.end()){
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};

// Time: O(n)，但比較慢，要所有資料都跑完才比較；space: O(n)
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         if(nums.size()<=1) return false;
//         unordered_set<int> seen(nums.begin(),nums.end());
//         if(seen.size()!=nums.size()) return true;
//         return false;
//     }
// };

// Time: O(nlogn)；space: O(1)
// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
//         if(nums.size()<=1) return false;
//         sort(nums.begin(),nums.end());
//         int prev=nums[0];
//         bool same=false;
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]==prev){
//                 same=true;
//                 break;
//             }
//             prev=nums[i];
//         }
//         return same;
//     }
// };
// @lc code=end

