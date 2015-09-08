#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    struct NodeT {
        int num;
        int index;
        NodeT(int n, int d) {
            num = n;
            index = d;
        }
        friend bool operator<(NodeT a, NodeT b) {
            return a.num < b.num;
        }
    };

    vector<int> twoSum(vector<int> arr, int target) {
        vector<int> ans;
        vector<NodeT> t;
        for (int i = 0; i < arr.size(); i++) {
            NodeT nt(target - arr[i], i);
            t.push_back(nt);
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < t.size(); i++) {
            if (binary_search(arr.begin(), arr.end(), t[i].num)) {
                ans.push_back(t[i].index+1);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution a;
    return 0;
}