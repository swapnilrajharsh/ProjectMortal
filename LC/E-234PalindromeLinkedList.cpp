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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;

        if (head->next == NULL) return true;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        reverseLinkedList(slow);

        // printLL(head);

        return palindromeCheck(head, slow->next);
    }

    void reverseLinkedList(ListNode *ptr) {
        ListNode *start = ptr->next, *prev = nullptr;

        while (start != NULL) {
            ListNode *next = start->next;
            start->next = prev;
            prev = start;
            start = next;
        }
        if (prev != NULL) { // It has moved ahead - LL has more than 2 elements
            ptr->next = prev; // Last Node will now be the next to mid
        }
    }

    void printLL(ListNode *ptr) {
        ListNode *temp = ptr;

        while (temp != NULL) {
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
    }

    bool palindromeCheck(ListNode *lStart, ListNode *rStart) {
        while (rStart != NULL) {
            if (lStart->val != rStart->val) return false;
            lStart = lStart->next;
            rStart = rStart->next;
        }
        return true;
    }
};