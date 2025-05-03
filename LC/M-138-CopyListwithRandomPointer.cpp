/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;
        
        Node *ptr = head;

        // Create copy of the Linked List
        // Original Node's next -> New Node (Duplicate)
        // Cloned node's next = Original Node's Next
        while (ptr != NULL) {
            Node *newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = ptr->next->next;
        }

        // Assign the random pointer to its counter cloned node
        ptr = head;
        while(ptr != NULL) {
            if (ptr->random == NULL)
                ptr->next->random = NULL;
            else
                ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }

        // Restore the Linked list
        ptr = head;
        Node *result = new Node(-1);
        Node *temp = result;

        while(ptr != NULL) {
            temp->next = ptr->next;
            ptr->next = ptr->next->next;
            ptr = ptr->next;
            temp = temp->next;

        }

        // printLinkedList(head);
        return result->next;
    }

    void printLinkedList(Node* head) {
        Node *ptr = head;
        while(ptr != NULL) {
            std::cout<<ptr->val<<" ";
            ptr = ptr->next;
        }
    }
};