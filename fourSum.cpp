// https://leetcode.com/problems/4sum/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int> &num, int target) {
        int size = num.size();
        map<int, vector<pair<int, int> > >cache;
        sort(num.begin(), num.end());

        for (int i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                cache[num[i]+num[j]].push_back(pair<int, int>(i, j));
            }
        }

        set<vector<int> > result;
        for (int i = 2; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                int key = target - num[i] - num[j];
                if (cache.find(key) != cache.end()) {
                    for (int k = 0; k < cache[key].size(); k++) {
                        if (i <= cache[key][k].second) continue;    // overlap
                        result.insert(vector<int> { num[cache[key][k].first], 
                            num[cache[key][k].second], num[i], num[j]
                        });
                    }
                }
            }
        }
        return vector<vector<int> > (result.begin(), result.end());
    }
};

int main() {
    Solution sol;
    vector<int> num;
    int n, e;
    cin >> n;
    while (n-- > 0) {
        num.push_back(e);
    }
    cin >> e;

    vector<vector<int> > ans = sol.fourSum(num, e);
    cout << "Case answer: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << "{";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
