// https://leetcode.com/problems/linked-list-cycle-ii/

#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) 
            return NULL;
        ListNode* first = head;
        ListNode* second = head;
        bool isCycle = false;
        while (first != NULL && second != NULL) {
            first = first->next;
            if (second->next == NULL)
                return NULL;
            second = second->next->next;
            if (first == second) {
                isCycle = true;
                break;
            }
        }
        if (!isCycle)
            return NULL;
        first = head;
        while (first != second) {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}