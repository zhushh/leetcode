// https://leetcode.com/problems/linked-list-cycle/

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode* first = head;
        ListNode* second = head;
        while (first != NULL && second != NULL) {
            first = first->next;
            if (second->next == NULL)
                return false;
            second = second->next->next;
            if (first == second)
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}