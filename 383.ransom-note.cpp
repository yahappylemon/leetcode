/*
 * @lc app=leetcode.cn id=383 lang=cpp
 * @lcpr version=30204
 *
 * [383] Ransom Note
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
    bool canConstruct(string ransomNote, string magazine) {
        int letters[26]={0};
        for(int i:magazine){
            letters[i-'a']++;
        }
        for(int i:ransomNote){
            letters[i-'a']--;
        }
        for(int i:letters){
            if(i<0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aab"\n
// @lcpr case=end

 */

