// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0, last = nums.size();
        while (first < last) {
            int mid = (first + last) / 2;
            if (nums[mid] == target) {
                return mid;
            } 
            // increasing from first to mid
            else if (nums[first] < nums[mid]) {
                if (nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid+1;
            }
            // increasing from mid  to last
            else {
                if (nums[mid] < target && target <= nums[last-1])
                    first = mid+1;
                else
                    last = mid;
            }
        }
        return -1;
    }
};
