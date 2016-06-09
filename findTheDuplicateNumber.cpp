// https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n;
        while (low < high) {
            int mid = (low+high) / 2;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid)
                    count++;
            }
            if (count > mid) high = mid;
            else low = mid+1;
        }
        return low;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    cout << "size: ";
    cin >> n;
    vector<int> v(n);
    cout << "seq: ";
    for (int i = 0; i < n;i++) {
        cin >> v[i];
    }
    cout << s.findDuplicate(v) << endl;
    return 0;
}
