/*
 * @lc app=leetcode.cn id=2319 lang=cpp
 * @lcpr version=30204
 *
 * [2319] Check if Matrix Is X-Matrix
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
    bool checkXMatrix(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                int current = grid[i][j];
                if(i==j && current==0) return false;
                if((i+j)==grid.size()-1 && current==0) return false;
                if(i!=j && (i+j)!=grid.size()-1 && current!=0) return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,0,0,1],[0,3,1,0],[0,5,2,0],[4,0,0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,7,0],[0,3,1],[0,5,0]]\n
// @lcpr case=end

 */

