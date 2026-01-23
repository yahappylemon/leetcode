/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(),stones.end());
        while(heap.size()>1){
            int s1 = heap.top();
            heap.pop();
            int s2 = heap.top();
            heap.pop();
            heap.push(abs(s1-s2));
        }
        return heap.size()==0?0:heap.top();
    }
};
// @lc code=end

