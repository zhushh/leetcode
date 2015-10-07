// https://leetcode.com/problems/word-pattern/

#include <iostream>
#include <string>
#include <vector> 
#include <map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> ss;
        string buff = "";
        for (auto c : str) {
            if (c != ' ') buff.push_back(c); else
            if (c == ' ' && buff != "") {
                ss.push_back(buff);
                buff = "";
            }
        }
        if (buff != "") ss.push_back(buff);
        if (ss.size() != pattern.size())
            return false;

        // mapping function
        map<string, char> f;
        map<char, string> g;
        f[ss[0]] = pattern[0];
        g[pattern[0]] = ss[0];
        for (int i = 1; i < pattern.size(); i++) {
            if (g.find(pattern[i]) != g.end() && f.find(ss[i]) == f.end())
                return false; 
            if (g.find(pattern[i]) == g.end() && f.find(ss[i]) != f.end())
                return false;
            if (g.find(pattern[i]) != g.end() && f.find(ss[i]) != f.end()) {
                if (g[pattern[i]] != ss[i] || f[ss[i]] != pattern[i])
                    return false;
            }
            else
            if (g.find(pattern[i]) == g.end() && f.find(ss[i]) == f.end()) {
                f[ss[i]] = pattern[i];
                g[pattern[i]] = ss[i];
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    string pattern, str;
    while (cin >> pattern) {
		str = "";
		for (int i = 0; i < pattern.size(); i++) {
			string temp;
			cin >> temp;
			str += " " + temp;
		}
        if (s.wordPattern(pattern, str)) {
            cout << "Get pattern" << endl;
        } else {
            cout << "Fail pattern" << endl;
        }
    }
    return 0;
}
