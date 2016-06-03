// https://leetcode.com/problems/subsets/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector< vector<int> > ans;
        int n = nums.size();
        for (int k = 1; k <= n; k++) {
            vector<int> cur(k);
            addKthSizeSubset(nums, ans, cur, 0, 0, n);
        }
        ans.push_back(vector<int>());
        return ans; 
    }

private:
    void addKthSizeSubset(vector<int> &nums, vector<vector<int> > &ans, vector<int> &cur, int idx, int curIdx, int& n) {
        if (curIdx == cur.size()) {
            ans.push_back(cur);
            return;
        }

        int left = cur.size() - curIdx - 1;
        for (int i = idx; i < n - left; i++) {
            cur[curIdx] = nums[i];
            addKthSizeSubset(nums, ans, cur, i+1, curIdx+1, n);
        }
    }
};

void print(vector< vector<int> > &ans) {
    int size = ans.size();
    cout << "ans size = " << size << endl;
    cout << "[" << endl;
    for (int i = 0; i < size; i++) {
        cout << "\t[";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
            if (j != ans[i].size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums(3);
    nums[0] = 1, nums[1] = 2, nums[2] = 3;
    vector< vector<int> > ans = s.subsets(nums);
    print(ans);
    return 0;
}
