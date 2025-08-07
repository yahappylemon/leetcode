/*
 * @lc app=leetcode.cn id=3438 lang=cpp
 * @lcpr version=30204
 *
 * [3438] Find Valid Pair of Adjacent Digits in String
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
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string findValidPair(string s) {
        unordered_map<int, int> mymap;
        string answer="";
        for(int i=0; i<s.size();i++){
            mymap[s[i]-'0']++;
        }
        for(int i=0; i<s.size()-1;i++){
            int current = s[i]-'0';
            int next = s[i+1]-'0';
            if(current!=next&& mymap[current]==current&& mymap[next]==next){
                answer+=to_string(current);
                answer+=to_string(next);
                break;
            }
        }
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "2523533"\n
// @lcpr case=end

// @lcpr case=start
// "221"\n
// @lcpr case=end

// @lcpr case=start
// "22"\n
// @lcpr case=end

 */

