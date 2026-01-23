/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
public:
    // min heap
    priority_queue<int, vector<int>, greater<int>> heap;
    int k;
    KthLargest(int k, vector<int>& nums):heap(nums.begin(),nums.end()),k(k) {
        while(heap.size()>k){
            heap.pop();
        }
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size()>k){
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

