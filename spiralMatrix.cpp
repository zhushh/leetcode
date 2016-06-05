// https://leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int m = matrix.size();
        if (m == 0) return vector<int>();
        int n = matrix[0].size();

        vector<int> ans;
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < (m+1)/2 && j < (n+1)/2) {
            // special case 1
            if (j == n - 1 - k) {
                while (i < m - k) {
                    ans.push_back(matrix[i++][j]);
                }
                break;
            }

            // from left to right
            while (j < n - 1 - k) {
                ans.push_back(matrix[i][j++]);
            }

            // special case 2
            if (i == m - 1 - k) {
                while (j < n - k) {
                    ans.push_back(matrix[i][j++]);
                }
                break;
            }

            // from up to down
            while (i < m - 1 - k) {
                ans.push_back(matrix[i++][j]);
            }

            // from right to left
            while (j > k) {
                ans.push_back(matrix[i][j--]);
            }

            // from down to up
            while (i > k) {
                ans.push_back(matrix[i--][j]);
            }

            i++;
            j++;
            k++;
        }
        return ans;
    }
};

void print(vector<int> ans) {
    cout << "output size = " << ans.size() << endl;
    cout << "sequence: ";
    for (int i = 0; i <ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

const int row = 2;
const int col = 10;

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int> > mat(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            mat[i][j] = col*i + j + 1;
        }
    }

    cout << "Init OK." << endl;
    print(s.spiralOrder(mat));
    return 0;
}