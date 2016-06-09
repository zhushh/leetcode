// https://leetcode.com/problems/excel-sheet-column-number/

#include <iostream>
#include <string>
using namespace std;

const int table[] = {
        1, 26, 676, 17576, 456976, 
        11881376, 308915776
};

class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            ans += (s[i] - 'A' + 1) * table[n-i-1];
        }
        return ans;
    }
    // inline int parameter(int k) {
    //     int num = 1;
    //     while (k-- > 1) {
    //         num *= 26;
    //     }
    //     return num;
    // }
};

int main(int argc, char const *argv[])
{
    string str;
    Solution s;
    while (cin >> str) {
        cout << s.titleToNumber(str) << endl;
    }
    return 0;
}
