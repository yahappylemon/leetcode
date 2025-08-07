/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30204
 *
 * [59] Spiral Matrix II
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer(n, vector<int>(n));
        //記錄起始位置
        int startx=0;
        int starty=0;
        int i, j;
        //控制每一圈、每一條邊的長度(末尾元素位置)
        int offset=1;
        int count=1;
        //矩陣會繞幾圈：剛好是n/2
        int round = n/2;
        while(round--){
            //維持左閉右開原則，最後一個元素交由下一條處理
            for(j=starty;j<n-offset;j++){
                answer[startx][j]=count;
                count++;
            }
            //退出迴圈時，j的值剛好為y座標的值
            for(i=startx;i<n-offset;i++){
                answer[i][j]=count;
                count++;
            }
            //退出迴圈時，i的值剛好為x座標的值
            for(;j>starty;j--){
                answer[i][j]=count;
                count++;
            }
            //退出迴圈時，j的值剛好為y座標的值
            for(;i>startx;i--){
                answer[i][j]=count;
                count++;
            }
            //起始位置向右下角更新
            //如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;
            offset++;
        }
        //如果是奇數，矩陣正中间的值要單獨處理
        if(n%2==1) answer[n/2][n/2] = n*n;
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

