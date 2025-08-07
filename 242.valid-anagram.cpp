/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30204
 *
 * [242] Valid Anagram
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
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26];
        for(char i:s){
            hash[i-'a']++;
        }
        for(char i:t){
            hash[i-'a']--;
        }
        for(int i:hash){
            if(i!=0) return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */

