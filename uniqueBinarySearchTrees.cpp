// Unique Binary Search Trees

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 0)
            return 0;
        vector<int> g(n+1, 0);
        g[0] = g[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                g[i] += g[j-1]*g[i-j];
            }
        }
        return g[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    while (cin >> n) {
        cout << s.numTrees(n) << endl;
    }
    return 0;
}