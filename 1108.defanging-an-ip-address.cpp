/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 * @lcpr version=30204
 *
 * [1108] Defanging an IP Address
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
    string defangIPaddr(string address) {
        string answer="";
        for(int i=0;i<address.length();i++){
            if(address[i]=='.'){
                answer+="[.]";
            }else{
                answer+=address[i];
            }
        }
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1.1.1.1"\n
// @lcpr case=end

// @lcpr case=start
// "255.100.50.0"\n
// @lcpr case=end

 */

