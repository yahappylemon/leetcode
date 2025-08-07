/*
 * @lc app=leetcode.cn id=2614 lang=cpp
 * @lcpr version=30204
 *
 * [2614] Prime In Diagonal
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
class Solution {
public:
    bool isPrime(int k){
        if(k<=1) return false;
        for(int i=2;i * i <= k;i++){
            if(k%i==0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int max = 0;
        for(int i=0;i<nums.size();i++){
            int a=nums[i][i];
            int b=nums[i][nums.size() - i - 1];
            if(isPrime(a)){
                if(a>max){
                    max=a;
                }
            }
            if(isPrime(b)){
                if(b>max){
                    max=b;
                }
            }
        }
        return max;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[5,6,7],[9,10,11]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[5,17,7],[9,11,10]]\n
// @lcpr case=end

 */

