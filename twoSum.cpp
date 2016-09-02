#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            if (mp.find(other) != mp.end()) {
                return vector<int> {mp[other], i};
            }
            mp[nums[i]] = i;
        }
        return vector<int>{};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v{2, 7, 11, 15};
    vector<int> ans = s.twoSum(v, 9);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}