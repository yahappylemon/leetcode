/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> circle;
        for(int i=1;i<=n;i++){
            circle.push_back(i);
        }
        auto head = circle.begin();
        while(circle.size()>1){
            if(head==circle.end()) head=circle.begin();
            auto victim = head;
            for(int i=1;i<k;i++){
                victim = next(victim);
                if(victim==circle.end()) victim=circle.begin();
            }
            head = circle.erase(victim);
        }
        auto winner = circle.begin();
        return *winner;
    }
};
// @lc code=end

