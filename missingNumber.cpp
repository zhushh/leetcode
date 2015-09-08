// https://leetcode.com/problems/missing-number/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    //int missingNumber(vector<int>& nums) {
    //    int size = nums.size();
    //    vector<bool> flag(size+1, false);
    //    for (int i = 0; i < size; i++) {
    //        flag[nums[i]] = true;
    //    }
    //    for (int i = 0; i <= size; i++) {
    //        if (!flag[i]) {
    //            return i;
    //        }
    //    }
    //    return -1;
    //}

    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }
        return size * (size+1) / 2 - sum;
    }
};

int main() {
    Solution a;
    int n, num;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    cout << a.missingNumber(nums) << endl;
    return 0;
}
