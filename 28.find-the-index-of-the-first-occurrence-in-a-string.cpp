/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30204
 *
 * [28] Find the Index of the First Occurrence in a String
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
    const long long A = 31;
    const long long MOD = 1e9+7;
    long long getHash(int i,int j, vector<long long> &hash_h, vector<long long> &power){
        if(i==0) return hash_h[j];
        long long res = hash_h[j] - hash_h[i-1] * power[j-i+1]%MOD;
        if(res<0) res+=MOD;
        return res;
    }
    int strStr(string haystack, string needle) {
        vector<long long> power(1e4,1);
        for(int i=1;i<power.size();i++){
            power[i]=power[i-1]*A%MOD;
        }
        int n = needle.size();
        int h = haystack.size();
        vector<long long> hash_n(n);
        vector<long long> hash_h(h);
        hash_n[0]=needle[0]-'a'+1;
        for(int i=1;i<n;i++){
            hash_n[i]=(hash_n[i-1]*A+(needle[i]-'a'+1))%MOD;
        }
        hash_h[0]=haystack[0]-'a'+1;
        for(int i=1;i<h;i++){
            hash_h[i]=(hash_h[i-1]*A+(haystack[i]-'a'+1))%MOD;
        }
        int index=-1;
        for(int i=0;i+n<=h;i++){
            long long res = getHash(i, i+n-1, hash_h, power);
            if(res==hash_n[n-1]){
                index = i;
                break;
            }
        }
        return index;
    }
    // 暴力解：O(n*m)
    // int strStr(string haystack, string needle) {
    //     int slow = 0;
    //     int same=0;
    //     int index=INT_MAX;
    //     for(int fast=0; fast<haystack.size();fast++){
    //         if(haystack[fast]==needle[slow]){
    //             same++;
    //             if(slow==needle.size()-1){
    //                 int startIndex = fast-needle.size()+1;
    //                 index = min(startIndex, index);
    //                 break;
    //             }
    //             slow++;
    //         }else{
    //             //調整 fast 的位置到相同字串的起始點
    //             //fast++後，會從下一個字元開始
    //             fast = fast - same; 
    //             same=0;
    //             slow=0;
    //         }
    //     }
    //     return index==INT_MAX? -1:index;
    // }
    //精簡暴力解
    // int strStr(string haystack, string needle) {
    //     //最後一個合法的開頭出現在 haystack 長度 - needle長度 的字元
    //     for (int i = 0; i <= haystack.size() - needle.size(); i++) {
    //         int slow = 0;
    //         while (slow < needle.size() && haystack[i + slow] == needle[slow]) {
    //             slow++;
    //         }
    //         if (slow == needle.size()) return i;
    //     }
    //     return -1;
    // }
};
// @lc code=end



/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */

