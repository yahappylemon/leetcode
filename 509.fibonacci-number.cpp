/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
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
class Solution {
public:
    // 矩陣快速冪
    class Matrix{
        public:
        vector<vector<int>> m;
        friend Matrix operator*(Matrix a, Matrix b){
            Matrix c;
            c.m={{0,0},{0,0}};
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    for(int k=0;k<2;k++){
                        c.m[i][j] = c.m[i][j]+a.m[i][k]*b.m[k][j];
                    }
                }
            }
            return c;
        }
    };
    Matrix fast_pow(Matrix m, int exponent){
        if(exponent==1) return m;
        if(exponent%2==1){
            return m * fast_pow(m, exponent-1);
        }else{
            m = m * m;
            return fast_pow(m, exponent/2);
        }
    }
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        Matrix base;
        base.m = {{1,1},{1,0}};
        base = fast_pow(base, n-1);
        return base.m[0][0]*1+base.m[0][1]*0;
    }
    // 遞迴解
    // int fib(int n) {
    //     if(n==0) return 0;
    //     if(n==1) return 1;
    //     return fib(n-1) + fib(n-2);
    // }
};
// @lc code=end

