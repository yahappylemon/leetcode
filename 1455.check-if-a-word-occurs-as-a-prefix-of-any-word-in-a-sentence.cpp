/*
 * @lc app=leetcode.cn id=1455 lang=cpp
 * @lcpr version=30204
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
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
#include <sstream>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string words;
        bool same = true;
        int index=1;
        while(ss>>words){
            for(int i=0;i<searchWord.size();i++){
                if(searchWord[i]!=words[i]) {
                    same=false;
                    break;
                }else{
                    same=true;
                }
            }
            if(same) return index;
            index++;
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "i love eating burger"\n"burg"\n
// @lcpr case=end

// @lcpr case=start
// "this problem is an easy problem"\n"pro"\n
// @lcpr case=end

// @lcpr case=start
// "i am tired"\n"you"\n
// @lcpr case=end

 */

