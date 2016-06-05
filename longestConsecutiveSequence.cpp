// https://leetcode.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int maxn = 0;
        int curCount = 0;
        int curVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            curCount = 0;
            if (numsSet.empty())
                break;

            curVal = nums[i];
            while (numsSet.find(curVal) != numsSet.end()) {
                curCount++;
                numsSet.erase(curVal--);
            }

            curVal = nums[i]+1;
            while (numsSet.find(curVal) != numsSet.end()) {
                curCount++;
                numsSet.erase(curVal++);
            }
            maxn = maxn < curCount? curCount : maxn;
        }

        return maxn;
    }
};
