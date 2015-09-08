// https://leetcode.com/problems/powx-n/

#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if (n >= 0) {
            for (int i = n; i > 0; i >>= 1) {
                if (i & 1) {
                    ans *= x;
                }
                x *= x;
            }
        } else {
            n = 0 - n;
            for (int i = n; i > 0; i >>= 1) {
                if (i & 1) {
                    ans /= x;
                }
                x *= x;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    double x;
    int n;
    while (cin >> x >> n) {
        printf("%.4lf\n", sol.myPow(x, n));
    }
    return 0;
}
