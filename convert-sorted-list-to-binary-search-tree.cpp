// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include <iostream>
#include <vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> linear = changeListToLinear(head);
        if (linear.size() <= 0) return NULL;

        return sortedListToBSTWithLegnth(linear, 0, linear.size());
    }

private:
    vector<ListNode*> changeListToLinear(ListNode* head) {
        vector<ListNode*> linear;
        while (head != NULL) {
            linear.push_back(head);
            head = head->next;
        }
        return linear;
    }

    TreeNode* sortedListToBSTWithLegnth(vector<ListNode*> &linear, int left, int right) {
        if (left >= right) return NULL;

        TreeNode* root = new TreeNode(0);
        if (right - left == 1) {
            root->val = linear[left]->val;
            return root;
        }

        int offset = (right - left)/2;

        ListNode* ptr = linear[offset+left];
        root->val = ptr->val;
        root->left = sortedListToBSTWithLegnth(linear, left, offset+left);
        root->right = sortedListToBSTWithLegnth(linear, offset+left+1, right);
        return root;
    }
};

void print(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main(int argc, char const *argv[])
{
    ListNode* lroot = new ListNode(1);
    lroot->next = new ListNode(2);
    lroot->next->next = new ListNode(3);
    lroot->next->next->next = new ListNode(4);
    lroot->next->next->next->next = new ListNode(5);

    Solution s;
    TreeNode* root = s.sortedListToBST(lroot);
    print(root);
    cout << endl << "Finished." << endl;
    return 0;
}
