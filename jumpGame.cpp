// https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        int n = nums.size();
        int index = 0;
        int length = nums[0];
        while (index < n && length > 0) {
            length--;
            length = max(length, nums[index++]);
        }
        return index == n;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}