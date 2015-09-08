// https://leetcode.com/problems/add-digits/

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return num - 9 * ((num-1)/9);
    }
};

int main() {
    Solution sol;
    int num;
    while (cin >> num) {
        cout << sol.addDigits(num) << endl;
    }
    return 0;
}
