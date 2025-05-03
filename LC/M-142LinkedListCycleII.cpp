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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        if (head == NULL || head->next == NULL) return nullptr;

        ListNode *fast = head;
        ListNode *start = head;
        
        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                //cout<<"slow : "<<slow->val<<endl;
                while (slow != start) {
                    slow = slow->next;
                    start = start->next;
                }
                return start;
            }
        }
        return nullptr;
    }
};