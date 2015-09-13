// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int first = 0, last = nums.size();
        while (first < last) {
            int mid = (first + last) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[first] < nums[mid]) {
                if (nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            } else if (nums[first] > nums[mid]) {
                if (nums[mid] < target && target <= nums[last-1])
                    first = mid + 1;
                else
                    last = mid;
            } else {
                first++;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n;
    int num;
    cin >> n;
    while (n-- > 0) {
		cin >> num;
        nums.push_back(num);
    }
    cin >> num;
    if (sol.search(nums, num)) {
        cout << "Exist array" << endl;
    } else {
        cout << "Can't find element" << endl;
    }
    return 0;
}
