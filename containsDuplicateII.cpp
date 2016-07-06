// https://leetcode.com/problems/contains-duplicate-ii/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            if (table.find(nums[i]) == table.end()) {
                table[nums[i]] = i;
            } else if (i - table[nums[i]] <= k) {
                return true;
            } else {
                table[nums[i]] = i;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}