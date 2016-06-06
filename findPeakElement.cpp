// https://leetcode.com/problems/find-peak-element/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }

private:
    int helper(vector<int>& nums, int low, int high) {
        if (low == high)
            return low;
        else {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if (nums[mid1] > nums[mid2])
                return helper(nums, low, mid1);
            else
                return helper(nums, mid2, high);
        }
    }
};

const int size = 4;

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
    cout << s.findPeakElement(v) << endl;
    return 0;
}