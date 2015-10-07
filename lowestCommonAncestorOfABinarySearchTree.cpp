/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (max(p->val, q->val) < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (min(p->val, q->val) > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
