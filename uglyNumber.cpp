// https://leetcode.com/problems/ugly-number/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num == 1) return true;
        while (num > 1) {
            if (num % 2 == 0) {
                num >>= 1;
            } else if (num % 3 == 0) {
                num /= 3;
            } else if (num % 5 == 0) {
                num /= 5;
            } else {
                return false;
            }
        }
        if (num == 1) return true;
        else return false;
    }
};

int main() {
    Solution a;
    int num;
    while (cin >> num) {
        if (a.isUgly(num)) {
            cout << "isUgly" << endl;
        } else {
            cout << "is not Ugly" << endl;
        }
    }
    return 0;
}
