// https://leetcode.com/problems/longest-valid-parentheses/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool ok(char a, char b) {
        return (a == '(' && b == ')');
    }
    int longestValidParentheses(string s) {
        int ans = 0;
        int size = s.size();
        vector<int> dp(size+1, -1);
        for (int i = 1; i < size; i++) {
            if (dp[i-1] == -1) {
                if (ok(s[i-1], s[i])) {
                    dp[i] = i-1;
                }
            } else {
                int index = dp[i-1];
                while (index > 0 && dp[index-1] != -1) index = dp[index-1];
                if (index > 0 && ok(s[index-1], s[i])) {
                    dp[i] = index-1;
                }
            }
            if (dp[i] != -1) {
                //ans = max(ans, i-dp[i]+1);
                int index = dp[i];
                while (index > 0 && dp[index-1] != -1) index = dp[index-1];
                ans = max(ans, i-index+1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s;
    while (cin >> s) {
        cout << sol.longestValidParentheses(s) << endl;
    }
    return 0;
}
