// https://leetcode.com/problems/3sum/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size-2; i++) {
            int a = nums[i];
            int st = i + 1;
            int et = size - 1;
            while (st < et) {
                int b = nums[st];
                int c = nums[et];
                if (a+b+c == 0) {
                    ans.push_back(vector<int> {a, b, c});
                    st++;
                    et--;
                    while (st < et && nums[st] == nums[st-1])
                        st++;
                    while (st < et && nums[et] == nums[et+1])
                        --et;
                } else if (a+b+c > 0) {
                    et--;
                } else {
                    st++;
                }
            }
            while (i < size - 2 && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};

#include <cstdio>
#include <ctime>

int main() {
    Solution sol;
    vector<int> data;
    int num;
    while (cin >> num) {
        data.push_back(num);
    }
    clock_t t;
    t = clock();
    vector<vector<int>> ans = sol.threeSum(data);

    cout << "Answer: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << "{";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    t = clock() - t;
    printf("Cost Time: %lf\n", ((double)t)/CLOCKS_PER_SEC);
    return 0;
}
