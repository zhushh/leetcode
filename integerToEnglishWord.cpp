// https://leetcode.com/problems/integer-to-english-words/

#include <iostream>
#include <string>
using namespace std;

string dict[] = {
    "Zero", "One", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", 
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
    "Sixteen", "Seventeen", "Eighteen", "Nineteen",
};

string tenths[] = {
    "Twenty", "Thirty", "Forty", "Fifty", "Sixty", 
    "Seventy", "Eighty", "Ninety"
};

class Solution {
public:
    string getDicts(int num) {
        if (num >= 0 && num < 20) {
            return dict[num];
        } else {
            return "";
        }
    }

    string getTenths(int num) {
        if (num >= 20 && num < 100) {
            return tenths[num/10 - 2];
        } else {
            return "";
        }
    }

    string changeToString(int num) {    // num < 1000
        if (num <= 0 || num >= 1000) {
            return "";
        }
        string ans = "";
        int t = num/100;
        if (getDicts(t) != "Zero") {
            ans += getDicts(t) + " Hundred";
        }
        t = (num%100);
        if (t > 0) {
            ans += (ans != "" ? " " : "");
        }
        if (t >= 20) {
            ans += getTenths(t);
            if (getDicts(t%10) != "Zero") {
                ans += " " + getDicts(t%10);
            }
        } else if (t > 0) {
            ans += getDicts(t);
        }
        return ans;
    }

    string numberToWords(int num) {
        string ans = "";
        int t = num / 1000000000;
        if (t > 0) {
            ans += changeToString(t) + " Billion";
        }
        t = (num % 1000000000) / 1000000;
        if (t > 0) {
            ans += (ans != "" ? " " : "");
            ans += changeToString(t) + " Million";
        }
        t = (num % 1000000) / 1000;
        if (t > 0) {
            ans += (ans != "" ? " " : "");
            ans += changeToString(t) + " Thousand";
        }
        t = (num % 1000);
        if (t > 0) {
            ans += (ans != "" ? " " : "");
            ans += changeToString(t);
        }
        if (ans == "") {
            return "Zero";
        } else {
            return ans;
        }
    }
};

int main() {
    Solution a;
    int num;
    while (cin >> num) {
        cout << a.numberToWords(num) << endl;
    }
    return 0;
}
