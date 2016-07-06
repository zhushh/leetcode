// https://leetcode.com/problems/binary-tree-paths/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL)
            return ans;
        
        string cur = std::to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(cur);
            return ans;
        }

        helper(ans, root->left, cur);
        helper(ans, root->right, cur);
        return ans;
    }

private:
    void helper(vector<string>& ans, TreeNode* root, string cur) {
        if (root == NULL)
            return;
        cur += ("->" + std::to_string(root->val));

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(cur);
        } else {
            helper(ans, root->left, cur);
            helper(ans, root->right, cur);
        }
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}