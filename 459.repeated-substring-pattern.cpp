/*
 * @lc app=leetcode.cn id=459 lang=cpp
 * @lcpr version=30204
 *
 * [459] Repeated Substring Pattern
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
    const long long MOD = 1e9+9;
    long long getHash(int i,int j,vector<long long> &hashed, vector<long long> &power){
        if(i==0) return hashed[j];
        long long res = hashed[j] - hashed[i-1] * power[j-i+1] % MOD;
        if(res<0) res+=MOD;
        return res;
    }
    bool repeatedSubstringPattern(string s) {
        vector<long long> power(1e4,1);
        for(int i=1;i<power.size();i++){
            power[i]=power[i-1]*A%MOD;
        }
        int n = s.size();
        vector<long long> hashed(n);
        hashed[0]=s[0]-'a'+1;
        for(int i=1;i<n;i++){
            hashed[i]=(hashed[i-1]*A+(s[i]-'a'+1))%MOD;
        }
        int length=0;
        for(int i=0;i<n-1;i++){
            length++;
            // 只檢查能整除 n 的長度
            if(n%length==0){
                int times = n/length;
                times--;
                int start = i+1;
                while(times--){
                    long long res = getHash(start, start+length-1, hashed, power);
                    if(hashed[i]!=res){
                        break;
                    }
                    start+=length;
                }
                if(times==-1) return true;
            }
        }
        return false;
    //暴力解：O(n^2)
    //    for(int len=1;len<s.size();len++){
    //         string needle=string(s.begin(), s.begin()+len);
    //         int times = s.size()/len;
    //         string answer="";
    //         while(times--){
    //             answer+=needle;
    //         }
    //         if(answer==s) return true;
    //    }
    //     return false;
    //移動匹配：O(n)，取決於find()
    //如果一個字串 s 是由子字串重複組成的，
    //s + s 去掉第一個字元和最後一個字元後，
    //原本的 s 一定會在裡面出現一次
    //     string concat = s+s;
    //     concat.erase(concat.begin());
    //     concat.erase(concat.end()-1);
    //     if(concat.find(s)!=string::npos){
    //      return true;
    //     }else{
    //         return false;
    //     }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abab"\n
// @lcpr case=end

// @lcpr case=start
// "aba"\n
// @lcpr case=end

// @lcpr case=start
// "abcabcabcabc"\n
// @lcpr case=end

 */

