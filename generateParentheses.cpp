// https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> ans;
        generate(ans, 0, 0, n, "");
        return vector<string>(ans.begin(), ans.end());
    }

private:
    void generate(set<string>& ans, int left, int right, int n, string cur) {
        if (left == n) {
            while (right++ < n) {
                cur += ")";
            }
            ans.insert(cur);
            return;
        }
        generate(ans, left+1, right, n, cur+"(");
        if (left > right) {
            generate(ans, left, right+1, n, cur+")");
        }
    }
};

void print(vector<string> v) {
    cout << "[" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    while (cin >> n) {
        print(s.generateParenthesis(n));
    }
    return 0;
}