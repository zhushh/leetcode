// https://leetcode.com/problems/single-number/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}