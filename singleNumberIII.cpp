// https://leetcode.com/problems/single-number-iii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;

        // find the value of a xor b
        for (int i = 0; i < nums.size(); i++) {
            diff ^= nums[i];
        }
        // find the diff bit between a and b
        diff &= -diff;

        vector<int> ans(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            // has not set diff bit
            if ((nums[i] & diff) == 0) {
                ans[0] ^= nums[i];
            }
            // set diff bit
            else {
                ans[1] ^= nums[i];
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}