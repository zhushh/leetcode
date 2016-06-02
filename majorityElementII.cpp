// https://leetcode.com/problems/majority-element-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> majorityElement(vector<int>& nums) {
            vector<int> ans;
            split(nums, 0, nums.size(), nums.size() / 3, ans);
            return ans;
        }

    private:
        void swap(int &a, int &b) {
            int c = a;
            a = b;
            b = c;
        }

        void split(vector<int> &nums, int left, int right, int len, vector<int> &ans) {
            if (left >= right) return ;
            int idx = (left + right) / 2;
            int val = nums[idx];
            int i = left+1;
            int j = left;
            int k = left;

            swap(nums[idx], nums[left]);
            while (i < nums.size()) {
                if (nums[i] < val) {
                    swap(nums[k++], nums[i]);
                    swap(nums[++j], nums[i++]);
                } else if (nums[i] == val) {
                    swap(nums[++j], nums[i++]);
                } else {
                    i++;
                }
            }

            if (j - k + 1 > len) ans.push_back(nums[k]);
            if (k - left >= len) split(nums, left, k, len, ans);
            if (right - j >= len) split(nums, j+1, right, len, ans);
        }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v(4);
    v[0] = 0;
    v[1] = 3;
    v[2] = 4;
    v[3] = 0;
    std::vector<int> vv = s.majorityElement(v);
    for (int i = 0; i < vv.size(); i++) {
        cout << vv[i] << " ";
    }
    cout << "Finished" << endl;
    return 0;
}