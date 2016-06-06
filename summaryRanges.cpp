// https://leetcode.com/problems/summary-ranges/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        string item = "";
        for (int i = 0; i < n; i++) {
            int idx = i;
            int st = nums[i];
            item = std::to_string(st);
            while (i < n && st == nums[i]) {
                i++;
                st++;
            }
            i--;
            if (i > idx) {
                item += "->";
                item += std::to_string(nums[i]);
            }
            ans.push_back(item);
        }
        return ans;
    }
};

void print(vector<string> ans) {
    cout << "[" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    cout << "]" << endl;
}

const int size = 5;

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v(size);
    for (int i = 0; i < size; i++)
        cin >> v[i];
    print(s.summaryRanges(v));
    return 0;
}