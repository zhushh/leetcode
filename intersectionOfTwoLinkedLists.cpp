// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int offset = 0;
        ListNode* first = headA;
        ListNode* second = headB;
        while (first != NULL && second != NULL) {
            first = first->next;
            second = second->next;
        }

        if (first != NULL) {
            while (first != NULL) {
                offset++;
                first = first->next;
            }
            first = headA;
            second = headB;
            while (offset-- > 0)
                first = first->next;
        } else {
            while (second != NULL) {
                offset++;
                second = second->next;
            }
            first = headA;
            second = headB;
            while (offset-- > 0)
                second = second->next;
        }

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