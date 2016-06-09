// https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int> nums(candidates.begin(), candidates.end());
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        vector<int> cur;
        helper(ans, nums, cur, target, 0);
        return ans;
    }

private:
    void helper(vector<vector<int> >& ans, vector<int>& nums, vector<int>& cur, int T, int idx) {
        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] > T)
                break;
            else if (nums[i] < T) {
                cur.push_back(nums[i]);
                helper(ans, nums, cur, T - nums[i], i);
                cur.pop_back();
            }
            else {
                cur.push_back(nums[i]);
                ans.push_back(cur);
                cur.pop_back();
                break;
            }
        }
    }
};

void print(vector<vector<int> > ans) {
    cout << "[" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << "    [";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

const int n = 4;

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v(n);
    cout << "array(size = 4): ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int target;
    cout << "target: ";
    cin >> target;
    print(s.combinationSum(v, target));
    return 0;
}
