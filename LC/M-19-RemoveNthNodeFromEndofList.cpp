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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *slow = head, *fast = head;
        
        int inc = 0;
        while (inc < n) {
            fast = fast->next;
            inc++;
        }

        if(fast == NULL)
            return head->next;
        
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        // Here we will have the kth element from last
        
        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        
        return head;

    }
};