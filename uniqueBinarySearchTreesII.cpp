// https://leetcode.com/problems/unique-binary-search-trees-ii/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0)
            return vector<TreeNode*>();
        else
            return generateTreesHelper(1,n);
    }

private:
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        if (start > end) {
            return vector<TreeNode*>(1, NULL);
        }

        vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generateTreesHelper(start, i-1);
            vector<TreeNode*> right = generateTreesHelper(i+1, end);

            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode* ptr = new TreeNode(i);
                    ptr->left = left[j];
                    ptr->right = right[k];
                    ans.push_back(ptr);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    while (cin >> n) {
        cout << s.generateTrees(n).size() << endl;
    }
    return 0;
}
