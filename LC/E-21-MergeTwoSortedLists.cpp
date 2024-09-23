/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        
        ListNode *head = NULL;
        ListNode *list1Temp = list1, *list2Temp = list2;

        if (list1Temp->val < list2Temp->val) {
            head = list1Temp;
            list1Temp = list1Temp->next;
        } else {
            head = list2Temp;
            list2Temp = list2Temp->next;
        }

        ListNode *result = head;
        

        while(list1Temp != NULL && list2Temp != NULL) {
            
            if (list1Temp->val < list2Temp->val) {
                result->next = list1Temp;
                list1Temp = list1Temp->next;
                result = result->next;
            } else {
                result->next = list2Temp;
                list2Temp = list2Temp->next;
                result = result->next;
            }
        }

        if (list1Temp != NULL) {
            result->next = list1Temp;
        }

        if (list2Temp != NULL) {
            result->next = list2Temp;
        }

        return head;
    }
};