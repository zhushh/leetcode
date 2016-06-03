// https://leetcode.com/problems/gas-station/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx = 0;
        int currentGas = 0;
        int tempGas = 0;

        int i = 0;
        int n = gas.size();
        while (i < n) {
            if (gas[i] >= cost[i]) {
                idx = i;
                tempGas = gas[i] - cost[i];
                i++;
                while (i < n && tempGas >= 0) {
                    tempGas += (gas[i] - cost[i]);
                    i++;
                }
                currentGas += tempGas;
            } else {
                currentGas += (gas[i] - cost[i]);
                i++;
            }
        }
        if (currentGas >= 0) {
            return idx;
        } else {
            return -1;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> gas(5);
    vector<int> cost(5);
    gas[0] = 4; gas[1] = 2; gas[2] = 2; gas[3] = 8; gas[4] = 4;
    cost[0] = 5; cost[1] = 3; cost[2] = 3; cost[3] = 4; cost[4] = 5;

    Solution s;
    cout << "Answer: " << s.canCompleteCircuit(gas, cost) << endl;

    vector<int> g;
    g.push_back(5);
    vector<int> c;
    c.push_back(4);

    cout << "Answer: " << s.canCompleteCircuit(g, c) << endl;
    return 0;
}
