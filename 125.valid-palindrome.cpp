/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
using namespace std;
#include <iostream>
#include <cctype>
#include <string>
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0) return true;
        int i=0,j=s.size()-1;
        while(i<j){
            // 避免全部都是標點符號或空白，索引越界
            while(i<j && !isalnum(s[i])){
                i++;
            }
            while(i<j && !isalnum(s[j])){
                j--;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end

