/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
using namespace std;
#include <iostream>
#include <vector>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int l=0,r=1;
        int maxProfit=0;
        while(r<prices.size()){
            // find a better time to buy
            if(prices[l]>prices[r]){
                l=r;
                r++;
            // sell and note down the maxProfit
            }else{
                int gap = prices[r] - prices[l];
                if(gap>maxProfit){
                    maxProfit = gap;
                }
                r++;
            }
        }
        return maxProfit;
    }
};
// @lc code=end

