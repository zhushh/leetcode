#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> tables(256, -1);
        int ans = 0, start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (tables[s[i]] > start)
                start = tables[s[i]];
            tables[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }

private:
    int max(int a, int b){
        return a > b? a : b;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string test;
    while (cin >> test) {
        cout << s.lengthOfLongestSubstring(test) << endl;
    }
    return 0;
}
