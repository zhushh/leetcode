#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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
    vector<int> case1;
    vector<int> case2;
    vector<NodeT> t;
    for (int i = 0; i < arr.size(); i++) {
        NodeT nt(target - arr[i], i);
        t.push_back(nt);
    }
    sort(arr.begin(), arr.end());
    int count_half = 0;
    for (int i = 0; i < t.size(); i++) {
        if (binary_search(arr.begin(), arr.end(), t[i].num)) {
            if (t[i].num * 2 == target) {
                count_half++;
                case1.push_back(t[i].index+1);
            } else {
                case2.push_back(t[i].index+1);
            }
            ans.push_back(t[i].index+1);
        }
    }
    // sort(ans.begin(), ans.end());
    if (count_half == 0) {
        sort(ans.begin(), ans.end());
        return ans;
    } else if (count_half == 1) {
        sort(case2.begin(), case2.end());
        return case2;
    } else {
        sort(case1.begin(), case1.end());
        return case1;
    }
    //return ans;
}

int main() {
    vector<int> a;
    int n, num, target;
    cout << "Input the source vector size: ";
    cin >> n;
    cout << "Input the target number: ";
    cin >> target;
    cout << "Now, input the arrary data: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }
    vector<int> ans = twoSum(a, target);
    cout << "The answer is: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
