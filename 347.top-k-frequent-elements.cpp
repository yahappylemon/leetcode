/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    struct compare{
        bool operator()(const pair<int,int> & a , const pair<int,int> & b){
            return a.second<b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> map;
        priority_queue<pair<int, int>,vector<pair<int, int>>, compare> pq;
        for(int i :nums){
            map[i]++;
        }
        for(auto it = map.begin();it!=map.end();++it){
            pair<int, int> c = {it->first,it->second};
            pq.push(c);
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

