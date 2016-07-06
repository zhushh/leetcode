// https://leetcode.com/problems/reorder-list/

#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL)
            return ;
        vector<ListNode*> vptr;
        ListNode* tmp = head;
        while (tmp != NULL) {
            vptr.push_back(tmp);
            tmp = tmp->next;
        }

        int n = vptr.size();
        for (int i = 0; i+i < n; i++) {
            vptr[i]->next = vptr[n - i - 1];
            vptr[n - i - 1]->next = vptr[i+1];
        }
        if (n % 2 == 1) {
            vptr[(n-1) / 2]->next = NULL;
        } else {
            vptr[n / 2]->next = NULL;
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}