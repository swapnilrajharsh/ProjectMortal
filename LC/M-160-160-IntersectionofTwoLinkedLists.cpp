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
        ListNode *l1 = headA, *l2 = headB;

        while (l1 != NULL && l2 != NULL) {
            if (l1 == l2 ) return l1;

            l1 = l1->next;
            l2 = l2->next;

            if (l1 == NULL && l2 == NULL) break;
            if (l1 == NULL) l1 = headB;
            if (l2 == NULL) l2 = headA;
        }

        return l1;
    }
};