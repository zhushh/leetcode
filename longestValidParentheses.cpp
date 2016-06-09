// https://leetcode.com/problems/longest-valid-parentheses/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.size();
        vector<int> record(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    record[i] = (i-2)>0? record[i-2]+2 : 2;
                } else {
                    int idx = i - record[i-1] - 1;
                    if (idx >= 0 && s[idx] == '(') {
                        record[i] = record[i-1] + 2 + ((idx-1 > 0? record[idx-1] : 0));
                    }
                }
                ans = max(ans, record[i]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str;
    while (cin >> str) {
        cout << s.longestValidParentheses(str) << endl;
    }
    return 0;
}
