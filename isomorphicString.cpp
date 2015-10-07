// https://leetcode.com/problems/isomorphic-strings/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) 
            return false;
 
        int f[256];
        int g[256];
        for (int i = 0; i < 256; i++) f[i] = g[i] = 256;
        f[t[0]] = s[0];
        g[s[0]] = t[0];
        for (int i = 1; i < s.size(); i++) {
            if (g[s[i]] != 256 && f[t[i]] == 256)
                return false;
            if (g[s[i]] == 256 && f[t[i]] != 256)
                return false;
            if (g[s[i]] != 256 && f[t[i]] != 256) {
                if (g[s[i]] != t[i] || f[t[i]] != s[i])
                    return false;
            } else {
                f[t[i]] = s[i];
                g[s[i]] = t[i];
            }
        }
        return true;
    }
};
