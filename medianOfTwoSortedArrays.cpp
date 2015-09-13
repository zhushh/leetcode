// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums2.size() + nums1.size();
        if (total & 0x1) {
            return find_kth(nums1, 0, nums2, 0, total/2+1);
        } else {
            return (find_kth(nums1, 0, nums2, 0, total/2) +
                                find_kth(nums1, 0, nums2, 0, total/2+1)) / 2;
        }
    }
private:
    static double find_kth(vector<int>& nums1, int st1, vector<int>& nums2, int st2, int k) {
        int m = nums1.size() - st1;
        int n = nums2.size() - st2;
        if (m > n) return find_kth(nums2, st2, nums1, st1, k);
        if (m == 0) return nums2[k - 1 + st2];
        if (k == 1) return min(nums1[st1], nums2[st2]);

        // divide k into tow parts
        int pa = min(k/2, m), pb = k - pa;
        if (nums1[pa - 1 + st1] < nums2[pb - 1 + st2])
            return find_kth(nums1, pa+st1, nums2, st2, k - pa);
        else if (nums1[pa - 1 + st1] > nums2[pb - 1 + st2])
            return find_kth(nums1, st1, nums2, pb+st2, k - pb);
        else
            return nums1[pa - 1 + st1];
    }
};

int main() {
    Solution sol;
    vector<int> a;
    vector<int> b;
    int na, nb, num;
    cin >> na >> nb;
    while (na-- > 0) {
        cin >> num;
        a.push_back(num);
    }
    while (nb-- > 0) {
        cin >> num;
        b.push_back(num);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << "median = " << sol.findMedianSortedArrays(a, b) << endl;
    return 0;
}
