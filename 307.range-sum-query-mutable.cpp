/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
    int size;
    vector<int> st;
    NumArray(vector<int>& nums) {
        size = int(nums.size());
        st.resize(nums.size()*4);
        build(1, 0, size-1, nums);
    }

    void build(int idx, int l, int r, vector<int>& nums){
        if(l==r){
            st[idx] = nums[l];
            return;
        }
        int mid=(l+r)/2;
        build(idx*2,l,mid,nums);
        build(idx*2+1,mid+1,r,nums);
        st[idx]=st[idx*2]+st[idx*2+1];
    }
    
    void update_detail(int idx, int l, int r, int index, int val){
        if(l==r){
            st[idx] = val;
            return;
        }
        int mid = (l+r)/2;
        if(index<=mid) update_detail(idx*2, l, mid, index, val);
        else update_detail(idx*2+1, mid+1, r, index, val);
        st[idx]=st[idx*2]+st[idx*2+1];
    }

    void update(int index, int val) {
        return update_detail(1, 0, size-1, index, val);
    }

    int sumRange_detail(int idx, int l, int r, int ql, int qr){
        if(ql>qr || ql>r || qr<l) return 0;
        if(ql<=l && r<=qr) return st[idx];
        int mid = (l+r)/2;
        return sumRange_detail(idx*2, l, mid, ql, qr)
            +sumRange_detail(idx*2+1, mid+1, r, ql, qr);
    }
    
    int sumRange(int left, int right) {
        return sumRange_detail(1, 0, size-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

