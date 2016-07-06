// https://leetcode.com/problems/contains-duplicate/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> ans(nums.begin(), nums.end());
        return ans.size() != nums.size();
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}